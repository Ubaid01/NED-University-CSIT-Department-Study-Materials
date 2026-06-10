#include<iostream>
using namespace std ;

struct Node {
    string val ;
    Node* next ;
    Node* prev ;
    Node( string str ) : val( str ) , next(nullptr) , prev(nullptr) {}
} ;

class BrowserHistory {
    private:
        Node* cur ;
    public:
        BrowserHistory( string homepage ) {
            cur = new Node( homepage ) ;
        }

        void visit( string url ) {
            // 1st delete all forward history.
            Node* temp = cur -> next ;
            while( temp ) {
                Node* front = temp -> next ;
                delete temp ;
                temp = front ;
            }

            Node* newNode = new Node( url ) ;
            newNode -> prev = cur ;
            cur -> next = newNode ;
            cur = newNode ; // Update pointer after each visit.
        }

        string back( int steps ) {
            while( steps && cur -> prev ) {
                cur = cur -> prev ;
                steps-- ;
            }
            return cur -> val ;
        }

        string forward( int steps ) {
            while( steps && cur -> next ) {
                cur = cur -> next ;
                steps-- ;
            }
            return cur -> val ;
        }

        ~BrowserHistory() {
            while( cur -> next )
                cur = cur -> next ;
            
            while( cur ) {
                Node* temp = cur -> prev ;
                delete cur ;
                cur = temp ;
            }
        }
} ;

int main(){
    BrowserHistory h("leetcode.com") ;
    h.visit("google.com") ;
    h.visit("facebook.com") ;
    h.visit("youtube.com") ;
    cout << h.back(1) << endl;
    cout << h.back(1) << endl;
    cout << h.forward(1) << endl;
    h.visit("linkedin.com") ;
    cout << h.forward(2) << endl;
    cout << h.back(2) << endl;
    cout << h.back(7) << endl;
    return 0;
}