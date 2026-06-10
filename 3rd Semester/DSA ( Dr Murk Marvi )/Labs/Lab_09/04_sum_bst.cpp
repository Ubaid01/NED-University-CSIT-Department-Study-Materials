#include<iostream>
#include"tree.cpp"
using namespace std;

int sumNodes( Node* root ) {
	if( !root )
		return 0 ;
	
	return root -> val + sumNodes( root -> left ) + sumNodes( root -> right ) ;	
}

int main() {
	BST t ;
	t.insert(20) ;
	t.insert(10) ;
	t.insert(5) ;
	t.insert(15) ;
	t.insert(25) ;
	t.insert(35) ;
	t.insert(23) ;
	t.insert( 50 ) ;

	cout << "Sum = " << sumNodes( t.root ) << endl ;
	return 0 ;
}