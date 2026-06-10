#include <iostream>
#include<string>
#include <thread>
// #include<mutex>
using namespace std ;

// mutex cout_mutex;
// Function that will be executed by each thread
void print_message(string message) {
    // lock_guard<mutex> lock(cout_mutex);
    cout << message << endl;
}

int main()
{
    string message1 = "Thread 1";
    string message2 = "Thread 2";
    string msg3 = "Doing print3" ;
    // Create threads
    thread thread1(print_message, message1);
    thread thread2(print_message, message2);
    thread thread3(print_message, msg3) ;

    // Wait for threads to finish
    thread1.join();
    thread2.join();
    thread3.join() ;

    cout << "Threads completed successfully" << endl;
    return 0;
}