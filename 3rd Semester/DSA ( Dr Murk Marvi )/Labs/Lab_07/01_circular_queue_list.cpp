#include<iostream>
using namespace std ;

struct Node {
    int val ;
    Node* next ;
    Node( int val ) : val(val) , next(nullptr) {}
} ;

class CircularQueue {
    private:
        Node* tail ; // Used tail instead of "head" as it will allow to get both head and front in O(1).
    public:
        CircularQueue( ) : tail(nullptr) {}
        bool isEmpty() { return tail ; }
        int front() { return ( tail ? tail -> next -> val : INT_MIN ) ; }
        int back() { return ( tail ? tail -> val : INT_MIN ) ; }

        void push( int data ) {
            Node* temp = new Node(data) ;
            if( !tail ) {
                tail = temp ;
                temp -> next = tail ;
            }
            else {
                temp -> next = tail -> next ;
                tail -> next = temp ;
                tail = temp ;
            }
        }

        void pop() {
            if( !tail )
                return ;

            if( tail -> next == tail ) {
                delete tail ;
                tail = nullptr ;
            }
            else {
                Node* temp = tail -> next ;
                tail -> next = tail -> next -> next ;
                delete temp ;
            }
        }

        void display() const {
            if( !tail ) {
                cout << "Queue is empty" << endl;
                return;
            }
            
            Node* cur = tail -> next ;
            do {
                cout << cur -> val << " " ;
                cur = cur -> next ;
            } while( cur != tail -> next ) ;
            cout << endl ;
        }

        ~CircularQueue() {
            if( !tail )
                return ;
            
            Node* cur = tail -> next ;
            while( cur != tail ) {
                Node* temp = cur ;
                cur = cur -> next ;
                delete temp ;
            }
            delete tail ;
            tail = nullptr ;
        }
} ;

int main(){
    CircularQueue Q ;
    Q.push(1) ;
    Q.push(2) ;
    Q.push(6) ;
    Q.pop() ;
    Q.pop() ;
    Q.push(5) ;
    Q.push(3) ;
    cout << "Front = " << Q.front() << " ; Back = " << Q.back() << endl ;
    Q.display() ;
    return 0;
}