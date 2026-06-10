#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t x;  // Protects readercount
sem_t y;  // Controls access to shared resource

int readercount = 0;

void* reader(void* arg) {
    int id = *((int*)arg);

    /*
        Decreases (locks) the semaphore.
        If semaphore value > 0 --> decrease by 1 and continue
        If value = 0 --> thread waits (blocks)
        Wait until resource is available, then take it
    */
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y);   // First reader blocks writers
    sem_post(&x); // Increases (unlocks) the semaphore. (I'm done. Resource is free now.)

    // Critical section
    cout << "Reader " << id << " is inside" << endl;
    usleep(100000); // simulate reading (0.1 sec)

    // Exit section
    sem_wait(&x);
    readercount--;
    if (readercount == 0)
        sem_post(&y);   // Last reader allows writers
    sem_post(&x);

    cout << "Reader " << id << " is leaving" << endl;

    pthread_exit(NULL);
}

// Writer function
void* writer(void* arg) {
    int id = *((int*)arg);

    cout << "Writer " << id << " is trying to enter" << endl;

    sem_wait(&y);  // Writer gets exclusive access

    // Critical section
    cout << "Writer " << id << " has entered" << endl;
    usleep(150000); // simulate writing (0.15 sec)

    cout << "Writer " << id << " is leaving" << endl;

    sem_post(&y);

    pthread_exit(NULL);
}

// g++ lab6.cpp -o lab6 -lpthread (pthread for Linux)
int main() {
    int n;
    cout << "Enter number of readers and writers: ";
    cin >> n;

    pthread_t readers[n], writers[n];
    int ids[n];

    /* 
        Initializes a semaphore before using it.
        sem --> Pointer to semaphore variable
        pshared ( 0 --> Shared between threads (most common case)
            1 --> Shared between processes

        value --> Initial value of semaphore ( value == 1 for mutext lock , > 1 for counting semaphore )
    */
    sem_init(&x, 0, 1); 
    sem_init(&y, 0, 1);
    for (int i = 0; i < n; i++) {
        ids[i] = i + 1;

        pthread_create(&readers[i], NULL, reader, &ids[i]);
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&x);
    sem_destroy(&y);
    return 0;
}
