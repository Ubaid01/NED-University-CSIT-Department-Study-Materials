#include <iostream>
using namespace std;
class IntQueue {
	private:
    int size;
    int count;
    int front;
    int rear;
    int* queue;

    void resize() {
        int* newQueue = new int[size*2];
        for (int i = 0; i < count; ++i) {
            newQueue[i] = queue[(front + i) % size];
        }

        delete[] queue;
        queue = newQueue;
        front = 0;
        rear = count - 1;
        size = size*2;
    }
public:
    IntQueue(int size = 4)
        : size(size), count(0), front(0), rear(-1), queue(new int[size]) {}

    ~IntQueue() {
        delete[] queue;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }

    void enqueue(int value) {// insert an element in the queue
        if (isFull()) {
            resize();
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
        count++;
    }

    int dequeue() { // remove an element from the queue
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int value = queue[front];
        front = (front + 1) % size;
        count--;
        return value;
    }

    int Front() const {// returns the front element from the qeueu
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return queue[front];
    }
    int Rear() const {// returns the last element from the qeueu
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return queue[rear];
    }


};

int main() {
    IntQueue q;
	
	cout << "Dequeued: " << q.dequeue() << endl;  
    cout << "Front: " << q.Front() << endl;         
    cout << "Rear: "  << q.Rear() <<endl;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeued: " << q.dequeue() << endl;  // Should print 10
    cout << "Front: " << q.Front() << endl;         // Should print 20

    q.enqueue(50);
    q.enqueue(60);

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    return 0;
}

