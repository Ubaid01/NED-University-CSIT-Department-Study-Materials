#include <iostream>
using namespace std;
struct Node { // Node class representing each element in the linked list
	 int data; // Data of the node
	 Node* next; // Pointer to the next node
	 Node(int data) { // Constructor to initialize the node with data and set next to nullptr
		 this->data = data;
		 this->next = nullptr;
	 }
};

class LinkedList { // LinkedList class representing the singly linked list
public:
 	Node* head; // Pointer to the first node in the list
	 LinkedList() { // Constructor to initialize the linked list
	 	head = nullptr;
	 }
	 void insert(int data) { // Insert a new node at the end of the list
		 Node* newNode = new Node(data); // Create a new node
		 if (head == nullptr) {
		 	head = newNode; // If list is empty, set head to the new node
		 } else {
			 Node* temp = head;
			 while (temp->next != nullptr) {
			 temp = temp->next; // Traverse to the last node
		 }
		 temp->next = newNode; // Set the next of the last node to new node
	 }
	 }
	void deleteNode(int key) { // Delete the first node with the given value
		Node* temp = head;
		Node* prev = nullptr;
	 	if (temp != nullptr && temp->data == key) { // If head node itself holds the key
	 		head = temp->next; // Move head to the next node
	 		delete temp; // Free the old head
	 		return;
	 	}
		while (temp != nullptr && temp->data != key) { // Search for the key to be deleted
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr) return; // If key was not present in the list
			 prev->next = temp->next; // Unlink the node from the linked list
			 delete temp; // Free the memory of the node
	 }
	 bool search(int key) { // Search for a node with a given value
		Node* temp = head;
		while (temp != nullptr) {
	 		if (temp->data == key) {
	 		return true; // Key found
	 		}
	 	temp = temp->next;
	 }
	 	return false; // Key not found
	 }
	 void display( Node* head ) { // Display the contents of the linked list
	 	Node* temp = head;
	 	while (temp != nullptr) {
	 		cout << temp->data << " -> ";
	 		temp = temp->next;
	 	}
	 	cout << "nullptr" << endl;
	 }
	 
	 ~LinkedList() {
	 	Node* cur = head ;
	 	while( cur ) {
	 		Node* temp = cur -> next ;
	 		delete cur ;
	 		cur = temp ;
		 }
		 head = nullptr ;
	 }
};
