#include<iostream>
#include"linked_list.cpp"

Node* merge( Node* h1 , Node* h2 ) {
	Node* temp = new Node(-1) ;
	Node* cur = temp ;
	
	// OR can use h1 && h2 and after that if( h1 ) cur -> next = h1 ; else if ( h2 ) cur -> next = h2 ;
	while( h1 || h2 ) {
		int val1 = (h1) ? h1 -> data : INT_MAX ;
		int val2 = (h2) ? h2 -> data : INT_MAX ;
		
		if( val1 < val2 ) {
			cur -> next = h1 ;
			h1 = h1 -> next ;
		}
		else {
			cur -> next = h2 ;
			h2 = h2 -> next ;
		}
		cur = cur -> next ;
	}
	cur = temp ;
	temp = temp -> next ;
	delete cur ;
	return temp ;
}

int main() {
	LinkedList l ;
	l.insert(1) ;
	l.insert(2) ;
	l.insert(4) ;
//	l.display() ;

	LinkedList l2 ;
	l2.insert(1) ;
	l2.insert(3) ;
	l2.insert(4) ;
	
	Node* res = merge( l.head , l2.head ) ;
	l.display( res ) ;
	return 0 ;
}