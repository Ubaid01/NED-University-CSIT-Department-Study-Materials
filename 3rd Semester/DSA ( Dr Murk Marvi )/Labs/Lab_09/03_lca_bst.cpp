#include<iostream>
#include"tree.cpp"
using namespace std;

Node* LCA( Node* root , int num1 , int num2 ) {
	if( !root )
		return root; 
	
	if( root -> val > num1 && root -> val > num2 )
		return LCA( root -> left , num1 , num2 ) ;
	else if( root -> val < num1 && root -> val < num2 )	
		return LCA( root -> right , num1 , num2 ) ;
	
	return root ; // Split-point
}

Node* LCA_Iterative( Node* root , int num1 , int num2 ) {
	if( !root )
		return nullptr ;
	
	Node* cur = root ;
	while( cur ) {
		if( cur -> val > num1 && cur -> val > num2 )
			cur = cur -> left ;
		else if( cur -> val < num1 && cur -> val < num2 )
			cur = cur -> right ;
		else // Split-Point
			return cur ;
	}
	return nullptr ;
}

int main() {
	BST t ;
	t.insert(40) ;
	t.insert(30) ;
	t.insert(25) ;
	t.insert(15) ;
	t.insert(35) ;
	t.insert(75) ;
	t.insert(60) ;
	t.insert( 50 ) ;
	
	Node* lca = LCA( t.root , 15 , 35 ) ;
	Node* lca2 = LCA_Iterative( t.root , 15 , 35 ) ;
	if( lca )
		cout << lca -> val << " " << endl ;
	else
		cout << "nullptr." << endl ;
	cout << ( lca2 ? to_string(lca2 -> val) : "nullptr." ) << endl ;
	return 0 ;
}