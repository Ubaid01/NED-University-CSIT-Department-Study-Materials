#include<iostream>
#include<deque>
using namespace std ;

struct Node {
    int val ;
    Node* next ;
    Node* prev ;
    Node( int val ) : val(val) , next(nullptr) , prev(nullptr) {} 
} ;

class DoubleEndedQueue {
    private:
        Node* head , *tail ;
        int size ;
    public:
        DoubleEndedQueue( ) : size(0) { 
            head = new Node(-1) ;
            tail = new Node(-1) ;
            head -> next = tail ;
            tail -> prev = head ;
        } 

        // bool isEmpty() { return size == 0 ; }
        bool isEmpty() { return head -> next == tail ; }
        int front() const { return ( head -> next != tail ) ? head -> next -> val : INT_MIN ; }
        int back() const { return ( tail -> prev != head ) ? tail -> prev -> val : INT_MIN ; }
        int Size() const { return size; }

        // Using DummyNodes to avoid if-else.
        void push_back( int value ) {
            Node* temp = new Node( value ) ;
            temp -> prev = tail -> prev ;
            temp -> next = tail ;
            tail -> prev -> next = temp ;
            tail -> prev = temp ;
            size++ ;
        }

        void push_front( int value ) {
            Node* temp = new Node( value ) ;
            temp -> next = head -> next ;
            temp -> prev = head ;
            head -> next -> prev = temp ; // MY-Error I was not changing OLD head's -> next previous link so it was showing same values.
            head -> next = temp ;
            size++ ;
        } 

        void pop_back( ) {
            if ( isEmpty() ) 
                return ;
            Node* temp = tail -> prev ;
            tail -> prev = temp -> prev ;
            temp -> prev -> next = tail ; // OLD Tail's -> prev -> prev -> next SHOULD point to tail.
            delete temp;
            size--;
        }

        void pop_front() {
            if( isEmpty() ) 
                return ;
            
            Node* temp = head -> next ;
            head -> next = temp -> next ;
            head -> next -> prev = head ; // As head's next is changed.
            delete temp;
            size-- ;
        }

        void display() {
            Node* temp = head -> next ;
            while( temp != tail ) {
                cout << temp -> val << " " ;
                temp = temp -> next ;
            }
            cout << endl ;
        }

        ~DoubleEndedQueue() {
            while ( !isEmpty() )
                pop_front() ;
            
            // In the end delete the dummy Nodes.
            delete head;
            delete tail;
        }
} ;

int main(){
    cout << "STL deque: " ;
    deque<int> DQ ;
    DQ.push_front( 3 ) ;
    DQ.push_back( 1 ) ;
    DQ.push_back( 2 ) ;
    DQ.push_front( 4 ) ;
    DQ.push_front( 7 ) ;
    cout << "Front = " << DQ.front() << endl ;
    cout << "Back = " << DQ.back() << endl ;
    cout << "Size = " << DQ.size() << endl ;
    DQ.pop_back( ) ;
    DQ.pop_front( ) ;
    deque<int>::iterator itr = DQ.begin() ;
    for( ; itr != DQ.end() ; ++itr )
        cout << *itr << " " ;
    cout << endl ;

    cout << "Custom Deque: " ;
    DoubleEndedQueue d ;
    d.push_front( 3 ) ;
    d.push_back( 1 ) ;
    d.push_back( 2 ) ;
    d.push_front( 4 ) ;
    d.push_front( 7 ) ;
    cout << "Front = " << d.front() << endl ;
    cout << "Back = " << d.back() << endl ;
    cout << "Size = " << d.Size() << endl ;
    d.pop_back() ;
    d.pop_front() ;
    d.display() ;
    return 0;
}