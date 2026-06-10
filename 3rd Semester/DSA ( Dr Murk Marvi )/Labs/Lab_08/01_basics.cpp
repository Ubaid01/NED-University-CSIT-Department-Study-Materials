#include<iostream>
#include "bin_tree.cpp"
using namespace std;

Node* searchVal( Node* root , int key ) {
	if( !root || root -> val == key )
		return root ;
	
	Node* left = searchVal( root -> left , key ) ;
	if( left )
		return left ;
	
	return searchVal( root -> right , key ) ;
}

void preOrder( Node* root ) {
	if( root ) {
		cout << root -> val << " " ;
		preOrder( root -> left ) ;
		preOrder( root -> right ) ;
	}
}

void postOrder( Node* root ) {
	if( root ) {
		postOrder( root -> left ) ;
		postOrder( root -> right ) ;
		cout << root -> val << " " ;
	}
}

int main() {
	/*
	      1
         / \
        2   3
       / \ / \
      5  8 7  9
     / \     / \
    11  4   15 12	*/
	Tree t ;
	t.root = new Node(1) ;
	t.root -> left = new Node(2) ;
	t.root -> left -> left = new Node(5) ;
	t.root -> left -> right = new Node(8) ;
	t.root -> left -> left -> left = new Node(11) ;
	t.root -> left -> left -> right = new Node(4) ;
	t.root -> right = new Node(3) ;
	t.root -> right -> left = new Node(7) ;
	t.root -> right -> right = new Node(9) ;
	t.root -> right -> right -> left = new Node(15) ;
	t.root -> right -> right -> right = new Node(12) ;
	
	Node* node = searchVal( t.root , 7 ) ;
	if( node )
		cout << node -> val << " " ;
	else
		cout << "nullptr " ;
	
	Node* node2 = searchVal( t.root , 17 ) ;
	if( node2 )
		cout << node2 -> val << endl ;
	else
		cout << "nullptr\n" ;
	
	cout << "Preorder: " ;
	preOrder( t.root ) ;
	cout << "\nPostorder: " ;
	postOrder( t.root ) ;
	cout << endl ;
	
	return 0 ;
	
}