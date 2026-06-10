#include<iostream>
#include"tree.cpp"
#include<stack>
using namespace std;

void minDiff( Node* root , Node* &prev , int& diff ) {
	if( !root )
		return ;
	
	minDiff( root -> left , prev , diff ) ; 
	if( prev )
		diff = min( diff , root -> val - prev -> val ) ;
		
	prev = root ; // Assign last inorder Node as it will have sorted element ; DON'T do other traversal as for BST their diffs will be large except for inorder.
	minDiff( root -> right , prev , diff ) ;  
}

int minDiff( Node* root ) {
	int diff = INT_MAX ;
	Node* temp = nullptr ;
	minDiff( root , temp , diff ) ;
	return diff ;
}

int minDiff_I( Node* root ) {
	if( !root )
		return 0 ;
	
	stack<Node*> stk ;
	Node *prev = nullptr ;
	Node *cur = root ;
	int minDiff = INT_MAX ;
	// Here use the inorder-Iterative traversal.
	while( !stk.empty() || cur ) {
		while( cur ) {
			stk.push( cur ) ;
			cur = cur -> left ;
		}

		cur = stk.top() ;
		stk.pop() ;
		if( prev ) // If used "int --> prev so can check if( prev > 0 ) for absolute min-diff."
			minDiff = min( minDiff, cur -> val - prev -> val ) ;
		
		prev = cur ;
		cur = cur -> right ;
	}
	return minDiff ;
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
	BST t2 ;
	t2.insert(4) ;
	t2.insert(2) ;
	t2.insert(6) ;
	t2.insert(1) ;
	t2.insert(3) ;

	cout << "Diff of t1 = " << minDiff( t.root ) << endl ;
	cout << "Iterative-Diff of t1 = " << minDiff_I( t.root ) << endl ;
	cout << "Diff of t2 = " << minDiff( t2.root ) << endl ;
	cout << "Iterative-Diff of t2 = " << minDiff_I( t2.root ) << endl ;
	return 0 ;
}