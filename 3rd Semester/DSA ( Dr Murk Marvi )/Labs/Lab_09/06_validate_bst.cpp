#include<iostream>
#include"tree.cpp"
using namespace std;

bool validateBST( Node* root , long long lowerBound , long long upperBound ) {
	if( !root )
		return true ;
	
	if( root -> val <= lowerBound || root -> val >= upperBound )
		return false ;
		
	return validateBST( root -> left , lowerBound , root -> val ) && validateBST( root -> right , root -> val , upperBound ) ;	
}

int main() {
	Node* root = new Node(5) ;
	root -> left = new Node(1) ;
//	root -> left -> right = new Node(6) ; // check for not-BST.
	root -> left -> right = new Node(4) ;
	root -> right = new Node(7) ;
	
	Node* root2 = new Node(100) ;
	root2 -> left = new Node(70) ;
	root2 -> right = new Node(120) ;
	root2 -> left -> left = new Node(55) ;
	root2 -> left -> right = new Node(85) ;
	root2 -> left -> right -> right = new Node(110) ; 
	root2 -> right -> left = new Node(90) ;
	root2 -> right -> right = new Node(130) ;
	
	cout << boolalpha << validateBST( root , LONG_LONG_MIN , LONG_LONG_MAX ) << endl ;
	cout << boolalpha << validateBST( root2 , LONG_LONG_MIN , LONG_LONG_MAX ) << endl ;
	return 0 ;
}