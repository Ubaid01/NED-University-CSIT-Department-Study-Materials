#include<iostream>
#include"linked_list.cpp"

Node* middle( Node* head ) {
	if( !head )
		return head ;
		
	Node* slow = head ;
	Node* fast = head ;
	while( fast && fast -> next ) {
		slow = slow -> next ;
		fast = fast -> next -> next ;
	}
	return slow ;
}

Node* reverseList( Node* &head ) {
	if( !head || !head -> next )
		return head ;
	
	Node* cur = head ;
	Node* prev = nullptr ;
	while( cur ) {
		Node* front = cur -> next ;
		cur -> next = prev ;
		prev = cur ;
		cur = front ;
	}
	return prev ;
}

bool isPalindrome( Node* &head ) {
	Node* mid = middle( head ) ;
	Node* secondHalf = reverseList( mid ) ; // If error occurs so use mid -> next as we want to preserve the mid-link to remove the reversal.
	Node* secondHead = secondHalf ;
	
	Node* firstHalf = head ;
	while( secondHalf ) {
		if( secondHalf -> data != firstHalf -> data ) {
			reverseList( secondHead ) ;
			return false ;
		}
		
		firstHalf = firstHalf -> next ;
		secondHalf = secondHalf -> next;
	}
	
	reverseList( secondHead ) ;
	return true ;
}

int main() {
	LinkedList l ;
	l.insert(1) ;
	l.insert(2) ;
	l.insert(3) ;
	l.insert(2) ;
	l.insert(1) ;
	
	LinkedList l2 ;
	l2.insert(2) ;
	l2.insert(1) ;
	l2.insert(3) ;
	
	cout << boolalpha << isPalindrome( l.head ) << endl ;
	cout << boolalpha << isPalindrome( l2.head ) << endl ;
	l.display( l.head ) ;
	l2.display( l2.head ) ;
	return 0 ;
}