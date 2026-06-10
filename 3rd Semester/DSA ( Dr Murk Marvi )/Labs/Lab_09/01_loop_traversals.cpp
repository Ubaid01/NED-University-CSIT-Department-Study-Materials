#include<iostream>
#include"tree.cpp"
#include<stack>
using namespace std;

void preorderStack( Node* root ) {
	if( !root )
		return ;
	
	cout << "Preorder: " ;
	stack<Node*> stk ;
	stk.push( root ) ;
	while( !stk.empty() ) {
		Node* cur = stk.top() ;
		stk.pop() ;
		cout << cur -> val << " " ;
		if( cur -> right )
			stk.push( cur -> right ) ;
		if( cur -> left )
			stk.push( cur -> left ) ;
	}
	cout << endl ;
}

void postorderStack( Node* root ) {
	if( !root )
		return ;
	
	cout << "Postorder: " ;
	stack<Node*> stk ;

	/* 2 stack solution.
	stack<Node*> stk2 ;
	stk.push( root ) ;
	while( !stk.empty() ) {
		Node* cur = stk.top() ;
		stk.pop() ;

		stk2.push( cur ) ;
		if( cur -> left ) // Process right-subtree 1st then left as we need to store the leftest node on top of stack2. and need right subtree-before node for postorder.
			stk.push( cur -> left ) ;
		if( cur -> right )
			stk.push( cur -> right ) ;
	}

	while( !stk2.empty() ) {
		cout << stk2.top() -> val << " " ;
		stk2.pop() ;
	}	*/

	Node* cur = root ;
	while( !stk.empty() || cur ) {
		while( cur ) {
			stk.push( cur ) ;
			cur = cur -> left ;
		}
		
		Node* temp = stk.top() -> right ;
		if( temp != nullptr )
			cur = temp ;
		else {
			temp = stk.top() ;
			stk.pop() ;
			cout << temp -> val << " " ;
			while( !stk.empty() && stk.top() -> right == temp ) {
				temp = stk.top() ;
				stk.pop() ;
				cout << temp -> val << " " ;
			}
		}
	}
	cout << endl ;
}

int main() {
	BST t ;
	t.insert(40) ;
	t.insert(30) ;
	t.insert(25) ;
	t.insert(75) ;
	t.insert(60) ;
	t.insert(50) ;
	
	preorderStack( t.root ) ;
	postorderStack( t.root ) ;
	return 0 ;
}