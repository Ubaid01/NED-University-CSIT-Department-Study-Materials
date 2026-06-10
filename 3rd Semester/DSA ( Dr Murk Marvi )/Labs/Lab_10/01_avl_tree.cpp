#include<iostream>
using namespace std ;

struct Node {
	int val , height ;
	Node* left ;
	Node* right ;
	Node( int val ) : val( val ) , height(1) , left( nullptr ) , right( nullptr ) {}	
} ;

class AVL {
	private:
		Node* root ;
		
		int getHeight( Node* node ) {
			return ( node ) ? node -> height : 0 ;
		}
		
		void setHeight( Node* node ) {
			node -> height = 1 + max( getHeight( node -> left ) , getHeight( node -> right ) ) ;
		}
		
		int getBF( Node* node ) {
			return ( node ) ? getHeight( node -> left ) - getHeight( node -> right ) : 0 ;
		}
		
		void deleteTree( Node* node ) {
			if( node ) {
				deleteTree( node -> left ) ;
				deleteTree( node -> right ) ;
				delete node ;
			}
		}
	
		Node* leftRotation( Node* node ) {
			Node* temp = node -> right ;
			node -> right = temp -> left ;  // MISTAKE: 1t do this --> Temp's left subtree becomes node's right child
			temp -> left = node ;
			
			setHeight( node ) ;
			setHeight( temp ) ;
			return temp ;
		}
		
		Node* rightRotation( Node* node ) {
			Node* temp = node -> left ;
			node -> left = temp -> right ;
			temp -> right = node ;
			
			setHeight( node ) ;
			setHeight( temp ) ;
			return temp ;
		}
		
		Node* balanceNode( Node* node ) {
			setHeight( node ) ;
			
			int balance = getBF( node ) ;
			
			if( balance > 1 ) {
				if( getBF( node -> left ) < 0 )
					node -> left = leftRotation( node -> left ) ;
				
				return rightRotation( node ) ;
			}
			
			if( balance < -1 ) {
				if( getBF( node -> right ) > 0 )
					node -> right = rightRotation( node -> right ) ;
				
				return leftRotation( node ) ;
			}
			
			return node ;
		}
		
		Node* insert( Node* node , int key ) {
			if( !node )
				return new Node( key ) ;
			
			if( node -> val == key ) {
				cout << "Duplicates can't be present.\n" ;
				return node ;
			}
			else if( node -> val > key )
				node -> left = insert( node -> left , key ) ;
			else
				node -> right = insert( node -> right , key ) ;
			
			return balanceNode( node ) ;	
		}
		
		Node* getSuccessor( Node* node ) {
			if( !node )
				return nullptr ;
			
			while( node -> left )
				node = node -> left ;
			
			return node ;
		}
		
		Node* deleteNode( Node* node , int key ) {
			if( !node )
				return nullptr ;
			
			if( node -> val > key )
				node -> left = deleteNode( node -> left , key ) ;
			else if( node -> val < key )
				node -> right = deleteNode( node -> right , key ) ;
			else {
				if( !node -> left || !node -> right ) {
					Node* temp = ( node -> right ) ? node -> right : node -> left ;
					delete node ;
					return temp ;
				}
				else {
					Node* temp = getSuccessor( node -> right ) ;
					node -> val = temp -> val ;
					node -> right = deleteNode( node -> right , temp -> val ) ;
				}
			}
			return balanceNode( node ) ;
		}
		
		void inorder( Node* node ) {
			if( node ) {
				inorder( node -> left ) ;
				cout << node -> val << " " ;
				inorder( node -> right ) ;
			}
		}
		
	public:
		AVL( ) : root( nullptr ) {}
		void insert( int val ) {
			root = insert( root , val ) ;
		}
		
		void DeleteKey( int val ) {
			root = deleteNode( root , val ) ;
		}
		
		void display( ) {
			cout << "Root = " << root -> val << endl;
			inorder( root ) ;
			cout << endl ;
		}
		
		~AVL( ) {
			deleteTree( root ) ;
		}
};

int main() {
	AVL t ;
	t.insert(5);
	t.insert(10);
	t.insert(15);
	t.insert(20);
	t.insert(25);
	t.insert(30);
	t.insert(1);
	t.display() ;
	t.DeleteKey(20) ;
	t.display() ;
	return 0 ;
}