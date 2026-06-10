#include<iostream>
#include "bin_tree.cpp"
using namespace std;

bool isSymmetric_I( Node* root ) {
	if ( !root )
        return true ;

    queue<Node*> q ;
    q.push( root -> left ) ;
    q.push( root -> right ) ;
	// queue<pair<Node*, Node*>> q;
    // q.push( { root -> left , root -> right } ) ;

    while ( !q.empty() ) {
        Node* node1 = q.front() ; q.pop() ;
        Node* node2 = q.front() ; q.pop() ;

        if ( !node1 && !node2 )
            continue;

        if ( !node1 || !node2 || node1 -> val != node2 -> val )
            return false;

        q.push( node1 -> left ) ;
        q.push( node2 -> right ) ;
        q.push( node1 -> right ) ;
        q.push( node2 -> left ) ;
    }

    return true;
}

bool isSymmetric( Node* root1 , Node* root2 ) {
	if( !root1 || !root2 )
		return ( root1 == root2 ) ;
	
	if( root1 -> val != root2 -> val )
		return false ;
	
	return isSymmetric( root1 -> left , root2 -> right ) && isSymmetric( root1 -> right , root2 -> left ) ;
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
	
	/*
	        1
         /   \
        2     2
       / \    / \
      3   4  4   3
     / \ / \ / \ / \
    5  6 7 8 8 7 6 5
*/
	Tree t2 ;
	t2.root = new Node(1) ;
	t2.root -> left = new Node(2) ;
	t2.root -> right = new Node(2) ;
	t2.root -> left -> left = new Node(3) ;
	t2.root -> left -> right = new Node(4) ;
	t2.root -> right -> left = new Node(4) ;
	t2.root -> right -> right = new Node(3) ;
	t2.root -> left -> left -> left = new Node(5) ;
	t2.root -> left -> left -> right = new Node(6) ;
	t2.root -> left -> right -> left = new Node(7) ;
	t2.root -> left -> right -> right = new Node(8) ; 
	t2.root -> right -> left -> left = new Node(8) ;  
	t2.root -> right -> left -> right = new Node(7) ;  
	t2.root -> right -> right -> left = new Node(6) ;  
	t2.root -> right -> right -> right = new Node(5) ;  
	
	
	cout << boolalpha << isSymmetric( t.root -> left , t.root -> right ) << endl ;
	cout << boolalpha << isSymmetric_I( t.root ) << endl ;
	cout << boolalpha << isSymmetric( t2.root -> left , t2.root -> right ) << endl ;
	cout << boolalpha << isSymmetric_I( t2.root ) << endl ;
	return 0 ;
}