#include<iostream>
#include "bin_tree.cpp"
using namespace std;

int treeHeight( Node* root ) {
	if( !root )
		return 0 ;
	
	int lh = treeHeight( root -> left ) ;
	if( lh == -1 ) // We need to pass -1 on each subtree if found on any subtree to avoid check.
		return -1 ;

	int rh = treeHeight( root -> right ) ;
	
	if( rh == -1 || abs( lh - rh ) > 1 )
		return -1 ;

	return 1 + max( lh , rh ) ;
}

// O( 4 * n ) approach so calculate side-by-side of height
bool isBalanced( Node* root ) {
// 	if( !root )
// 		return true ;
	
// 	int left = treeHeight( root -> left ) ;
// 	int right = treeHeight( root -> right ) ;
	
// 	if( abs(left - right) > 1 )
// 		return false ;
		
// 	return isBalanced( root -> left ) && isBalanced( root -> right ) ;

	return treeHeight( root ) != -1 ;
}

int main() {
	Tree t ;
	t.root = new Node(3) ;
	t.root -> left = new Node(9) ;
	t.root -> right = new Node(20) ;
	t.root -> right -> left = new Node(15) ;
	t.root -> right -> right = new Node(7) ;	

	Tree t2 ;
	t2.root = new Node(1) ;
	t2.root -> left = new Node(2) ;
	t2.root -> right = new Node(2) ;
	t2.root -> left -> left = new Node(3) ;
	t2.root -> left -> right = new Node(3) ;
	t2.root -> left -> left -> left = new Node(4) ;
	t2.root -> left -> left -> right = new Node(4) ;
	
	cout << boolalpha << isBalanced( t.root ) << endl ;
	cout << boolalpha << isBalanced( t2.root ) << endl ;
	
	return 0 ;
}