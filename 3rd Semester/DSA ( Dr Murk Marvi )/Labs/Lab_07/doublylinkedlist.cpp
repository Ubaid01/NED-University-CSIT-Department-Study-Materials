#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;
    Node(int d) {
        val = d;
        next = nullptr ;
        prev = nullptr ;
    }
};

class DoublyLinkedList
{
private:
public:
    Node *head;
    // Constructor
    DoublyLinkedList() : head(nullptr ) {}
    void insertAtFront(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        newNode->prev = nullptr ;
        if (head != nullptr )
        {
            head->prev = newNode; // Update previous pointer of the old head
        }
        head = newNode;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = nullptr ;
        if (head == nullptr )
        { // If the list is empty, make the new node the head
            newNode->prev = nullptr ;
            head = newNode;
            return;
        }
        // Otherwise, find the last node
        Node *temp = head;
        while (temp->next != nullptr )
        {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }
    void deleteNode(int value)
    { // Delete a node from the list by value
        Node *temp = head;
        // Traverse the list to find the node with the given value
        while (temp != nullptr  && temp->val != value)
        {
            temp = temp->next;
        }
        if (temp == nullptr )
        { // Node not found
            cout << "Node with value " << value << " not found." << endl;
            return;
        }
        if (temp->prev != nullptr )
        { // Update the previous node's next pointer
            temp->prev->next = temp->next;
        }
        else
        {
            // Node is the head
            head = temp->next;
        }
        if (temp->next != nullptr )
        { // Update the next node's previous pointer
            temp->next->prev = temp->prev;
        }
        // Free the memory of the node
        delete temp;
    }
    void displayForward( Node* head ) const
    {
        Node *temp = head;
        while (temp != nullptr )
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayBackward( Node* head ) const
    {
        Node *temp = head;
        // Traverse to the end of the list
        if (temp == nullptr )
            return;
        while (temp->next != nullptr )
        {
            temp = temp->next;
        }
        // Now traverse backward from the last node
        while (temp != nullptr )
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node *temp = head ;
        while ( temp != nullptr ) {
            Node *next = temp -> next ;
            delete temp ;
            temp = next ;
        }
    }
};