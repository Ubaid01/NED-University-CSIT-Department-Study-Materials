#include<iostream>
#include"doublylinkedlist.cpp"
using namespace std ;

Node* helper( Node* l , Node* m ) {
    // Else will have to create deep-copy.
    if ( !l ) 
        return m ;
    if ( !m ) 
        return l ;

    Node* head = l ;
    Node* lastL = head ;
    while ( lastL -> next )
        lastL = lastL -> next ;

    lastL -> next = m ;

    if ( m )
        m -> prev = lastL ;

    return head ;
}

Node* concatenateLists( Node* l , Node* m ) {
    Node* list = helper( l , m ) ;
    m -> prev = nullptr ;
    return list ;
}

Node* merge( Node* &h1 , Node* &h2 ) {
    if( !h1 )
        return h2 ;
    
    if( !h2 )
        return h1 ;
    
    Node* dummy = new Node(-1) ;
    Node* cur = dummy ;
    Node* temp1 = h1 , *temp2 = h2 ;
    while( temp1 && temp2 ) {
        if( temp1 -> val > temp2 -> val ) {
            cur -> next = temp1 ;
            temp1 -> prev = cur ;
            temp1 = temp1 -> next ;
        }
        else {
            cur -> next = temp2 ;
            temp2 -> prev = cur ;
            temp2 = temp2 -> next ;
        }
        cur = cur -> next ;
    }

    if( temp1 ) {
        cur -> next = temp1 ;
        temp1 -> prev = cur ;
    }
    else if ( temp2 ) {
        cur -> next = temp2 ;
        temp2 -> prev = cur ;
    }

    cur = dummy -> next ;
    delete dummy ;
    return cur ;
}

Node* middleElement( Node* &head ) {
    if( !head )
        return nullptr ;
    
    Node* slow = head ;
    Node* fast = head -> next ;
    while( fast && fast -> next ) {
        fast = fast -> next -> next ;
        // if( !fast )
        slow = slow -> next ;
    }

    Node* temp = slow -> next ;
    slow -> next = nullptr ;
    return temp ;
}

Node* mergeSort( Node* &head ) {
    if( !head || !head -> next )
        return head ;
    
    Node* middle = middleElement( head ) ;
    head = mergeSort( head ) ; // By manipulating original head directly ; can be sorted in original concatenated-list.
    middle = mergeSort( middle ) ;

    return merge( head , middle ) ;
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
    Node* sorted = mergeSort( n ) ;

    l.displayForward( sorted ) ;
    l.displayForward( n ) ;
    return 0;
}