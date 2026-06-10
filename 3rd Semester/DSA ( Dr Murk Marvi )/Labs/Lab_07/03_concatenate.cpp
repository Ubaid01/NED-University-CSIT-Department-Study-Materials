#include<iostream>
#include"doublylinkedlist.cpp"
using namespace std ;

Node* helper( Node* l , Node* m ) {
    // Else will have to create deep-copy of 1st list to avoid modification in original.
    if ( !l ) 
        return m ;
    if ( !m ) 
        return l ;

    Node* head = l ;
    Node* lastL = head ;
    while ( lastL -> next )
        lastL = lastL -> next ;

    lastL -> next = m ;
    m -> prev = lastL ;

    return head ;
}

Node* concatenateLists( Node* l , Node* m ) {
    Node* list = helper( l , m ) ;
    m -> prev = nullptr ; // To restore original list links.

    // We can't change this OR else links of l will be changed and only l's head will be returned.
    // Node* cur = l ;
    // while( cur -> next != m )
    //     cur = cur -> next ;
    
    // cur -> next = nullptr ;

    return list ;
}

int main(){
    DoublyLinkedList l ;
    DoublyLinkedList m ;

    for( int i = 1 ; i <= 10 ; i++ ) {
        if( i % 2 == 0 )
            l.insertAtEnd( i ) ;
        else
            m.insertAtEnd( i ) ;
    }

    Node* n = concatenateLists( l.head , m.head ) ;
    l.displayForward( n ) ;
    l.displayForward( l.head ) ;
    l.displayForward( m.head ) ;
    return 0;
}