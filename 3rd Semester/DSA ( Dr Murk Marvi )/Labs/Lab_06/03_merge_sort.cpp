#include<iostream>
#include"linked_list.cpp"

Node* merge( Node* l1, Node* l2 ) {
    if ( !l1 ) 
		  return l2 ;
    if ( !l2 ) 
		  return l1 ;

    if ( l1  ->  data < l2  ->  data ) {
        l1  ->  next = merge( l1  ->  next, l2 ) ;
        return l1 ;
	}
    else {
        l2  ->  next = merge( l1 , l2  ->  next ) ;
        return l2;
    }
}

Node* getMiddle(Node* head) {
    if (!head || !head  ->  next) 
		return head;

    Node* slow = head ;
    Node* fast = head -> next ; // This was my error. To ensure that when we split the linked list into two halves, the first half contains one fewer node than or equal to second half in case the list has an odd number of elements.

    while (fast && fast -> next) {
        slow = slow  ->  next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node* mergeSort(Node* head) {
    if (!head || !head -> next) 
		return head;

    Node* middle = getMiddle(head);
    Node* temp = middle -> next;
    middle -> next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(temp);

    Node* sortedList = merge(left, right);
    return sortedList;
}

int main() {
	LinkedList l ;
	l.insert(4) ;
	l.insert(2) ;
	l.insert(1) ;
	l.insert(3) ;
	
	Node* sorted = mergeSort( l.head ) ;
	l.display( sorted ) ;
	return 0 ;
}