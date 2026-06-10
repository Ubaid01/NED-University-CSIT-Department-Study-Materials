#include<iostream>
#include"linked_list.cpp"

void removeDuplicates( Node* &head ) {
	if( !head || !head -> next )
		return ;
		
	Node* cur = head ;
	Node* fast = head -> next ;
	while( fast ) {
		while( fast && cur -> data == fast -> data )
			fast = fast -> next ;

		cur -> next = fast ;
		cur = cur -> next ;
		fast = ( fast ) ? fast -> next : nullptr ; // Errored without it.
	}
}

int main() {
	LinkedList l ;
	l.insert(1) ;
	l.insert(1) ;
	l.insert(1) ;
	l.insert(2) ;
	l.insert(3) ;
	l.insert(3) ;
	l.insert(4) ;
	
	removeDuplicates( l.head ) ;
	l.display( l.head ) ;
	return 0 ;              
	
}
         