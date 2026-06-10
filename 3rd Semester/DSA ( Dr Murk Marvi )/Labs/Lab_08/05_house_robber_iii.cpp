#include<iostream>
#include "bin_tree.cpp"
#include<unordered_map>
using namespace std;

// DP-Question as robber can rob any non-adjacent ( no-two same link ) house having max-money like 4,1,2,3 so 4 + 3 = 7.
int solve( Node* root , unordered_map<Node*,int>& memo ) {
	if( !root )
		return 0 ;

	if( memo[root] )
		return memo[root] ;
	
	int leave = solve( root -> left , memo ) + solve( root -> right , memo ) ;
	int take = root -> val ;
	if( root -> left ) 
		take += solve( root -> left -> left , memo ) + solve( root -> left -> right , memo ) ;
	if( root -> right )
		take += solve( root -> right -> left , memo ) + solve( root -> right -> right , memo ) ;
	
	return memo[root] = max( leave , take ) ;
}

int houseRobber(Node* root) {
	unordered_map<Node*,int> memo ;
	return solve( root , memo ) ;
}

int main() {
	Tree t ;
	t.root = new Node(4) ;
	t.root -> left = new Node(1) ;
	t.root -> right = new Node(3) ;
	t.root -> left -> right = new Node(3) ;
	t.root -> right -> right = new Node(1) ;
	
	Tree t2 ;
	t2.root = new Node(3) ;
	t2.root -> left = new Node(4) ;
	t2.root -> right = new Node(5) ;
	t2.root -> left -> left = new Node(1) ;
	t2.root -> left -> right = new Node(3) ; 
	t2.root -> right -> right = new Node(1) ; 

	Tree t3 ;
	t3.root = new Node(4) ;
	t3.root -> left = new Node(1) ;
	t3.root -> left -> left  = new Node(2) ;
	t3.root -> left -> left -> left = new Node(3) ;

	cout << houseRobber( t.root ) << endl ;
	cout << houseRobber( t2.root ) << endl ;
	cout << houseRobber( t3.root ) << endl ;
	return 0 ;
}