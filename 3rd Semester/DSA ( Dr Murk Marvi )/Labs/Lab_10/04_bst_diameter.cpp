#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

struct Node {
	int val ;
	Node* left ;
	Node* right ;
	Node( int val ) : val( val ) , left( nullptr ) , right( nullptr ) {}	
	
	void deleteTree( Node* node ) {
		if( node ) {
			deleteTree( node -> left ) ;
			deleteTree( node -> right ) ;
			delete node ;
		}
	}
} ;

int height( Node* root , int& res ) {
	if( !root )
		return 0 ;
	
	int left = height( root -> left , res ) ;
	int right = height( root -> left , res ) ;
	
	res = max( res , left + right ) ; // +1 for nodes diameter.
	return 1 + max( left ,right ) ;
}

int maxDiameter( Node* root ) {
	int res = 0 ;
	height( root , res ) ;
	return res ;
}

int main() {
	Node* root = new Node(-10) ;
	root -> left = new Node(-2) ;
	root -> right = new Node(4) ;
	root -> left -> left = new Node(100) ;
	root -> left -> right = new Node(10) ;
	root -> left -> right -> right = new Node(0) ;
	root -> left -> right -> right -> right = new Node(-5) ;
	cout << "Diameter = " << maxDiameter( root ) << endl ;
	root -> deleteTree( root ) ;
	return 0 ;
}