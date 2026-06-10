#include<iostream>
#include<vector>
using namespace std;

const int BUFSIZE = 10 ;

struct Node
{
    int val;
    Node* next;
};

Node* head = nullptr ;
Node* tail = nullptr ;
int countNodes = 0 ;

void produceLL() {
    if (countNodes == BUFSIZE) {
        cout << "Buffer is Full";
        return;
    }

    int value;
    cout << "Enter value to produce: ";
    cin >> value;

    Node* temp = new Node();
    temp -> val = value;
    temp -> next = nullptr ;

    if ( !head )
        head = tail = temp;
    else {
        tail -> next = temp ;
        tail = temp ;
    }
    countNodes++ ;
}

void consumeLL() {
    if ( !countNodes ) {
        cout << "Buffer is Empty";
        return;
    }

    Node* temp = head ;
    cout << "Consumed value: " << temp->val;
    head = head -> next ;
    delete temp ;
    countNodes-- ;

    if ( !head )
        tail = nullptr;
}

void producerConsumerLinkedList() {
    int choice = 0;
    cout << "Linked List Buffer Size: " << BUFSIZE << endl ;
    cout << "\n1. Produce\n2. Consume\n3. Exit";
    while (choice != 3) {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                produceLL();
                break;
            case 2:
                consumeLL();
                break;
            case 3:
                cout << "Exiting Linked List Producer-Consumer...";
                break;
            default:
                cout << "Invalid choice!";
        }
    }
}

int main() {
    producerConsumerLinkedList();
    return 0;
}
