#include<iostream>
using namespace std;

struct Node {
	int val ;
	Node* next ;
	Node( int v = 0 ) : val(v) , next( nullptr ) {}
	
} ;

class Stack {
	Node* head ;
	public:
		Stack( ) : head(nullptr) {}
		bool isEmpty() { return ( !head ) ; }
		void push( int data ) {
			if( !head )
				head = new Node( data ) ;
			else {
				Node* temp = new Node( data ) ;
				temp -> next = head ;
				head = temp ;
			}
		}
		
		void pop() {
			if( isEmpty() )
				return ;
			else if( !head -> next ) {
				delete head ;
				head = nullptr ;
			}
			else {
				Node* temp = head ;
				head = head -> next ;
				delete temp ;
			}
		}
		
		int top() {
			return ( head ) ? head -> val : -1 ;
		}
		
		void display() const {
			Node* p = head ;
			while( p ) {
				cout << p -> val << " " ;
				p = p -> next ;
			}
		}
		~Stack() {
			Node* cur = head ;
			while( cur ) {
				Node* next = cur -> next ;
				delete cur ;
				cur = next ;
			}
			head = nullptr ;
		}
};

int main() {
	Stack s ;
	s.push(10) ;
	s.push(20) ;
	s.push(30) ;
	s.push(40) ;
	cout << "Top = " << s.top() << endl ;
	s.pop() ;
	cout << "Top = " << s.top() << endl ;
	s.display() ;

	return 0 ;
}