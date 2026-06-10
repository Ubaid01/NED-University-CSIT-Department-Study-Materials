#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

struct TreeNode {
	int val ;
	TreeNode* left ;
	TreeNode* right ;
	TreeNode( int val ) : val( val ) , left( nullptr ) , right( nullptr ) {}	
	
	void deleteTree( TreeNode* node ) {
		if( node ) {
			deleteTree( node -> left ) ;
			deleteTree( node -> right ) ;
			delete node ;
		}
	}
} ;

struct ListNode {
	int val ;
	ListNode* next ;
	ListNode( int val ) : val( val ) , next(nullptr) {}
	
	void deleteList( ListNode* node ) {
		ListNode* cur = node ;
		while( cur ) {
			ListNode* temp = cur -> next ;
			delete cur ;
			cur = temp ;
		}
	}
} ;

ListNode* middleNode( ListNode* node , ListNode* &leftTail ) {
	if( !node )
		return nullptr ;
	
	leftTail = nullptr ;
	ListNode* slow = node ;
	ListNode* fast = node -> next ;
	
	while( fast && fast -> next ) {
		leftTail = slow ;
		fast = fast -> next -> next ;
		slow = slow -> next ;
	}

	return slow ;
}

TreeNode* listToBST( ListNode* head ) {
	if( !head )
		return nullptr ;
	if( !head -> next )
		return new TreeNode( head -> val ) ;
	
	ListNode* leftTail = nullptr ;
	ListNode* middle = middleNode( head , leftTail ) ;
	TreeNode* root = new TreeNode( middle -> val ) ;
	
	if( leftTail ) {
		leftTail -> next = nullptr ;
	}
	else {
		root -> right = new TreeNode( middle -> next -> val ) ; // Directly assign "right" pointer if there is no-previous.
		return root ;	
	}
	
//	if( middle != head )
	root -> left = listToBST( head ) ;
	root -> right = listToBST( middle -> next ) ;
	return root ;
}

void inorder( TreeNode* node ) {
	if( node ) {
		inorder( node -> left ) ;
		cout << node -> val << " " ;
		inorder( node -> right ) ;
	}
}

int main() {
	ListNode* head = new ListNode(-10) ;
	head -> next = new ListNode(-3) ;
	head -> next -> next = new ListNode(0) ;
	head -> next -> next -> next = new ListNode(5) ;
	head -> next -> next -> next -> next = new ListNode(9) ;
	TreeNode* root = listToBST( head ) ;
	inorder( root ) ;
	head -> deleteList( head ) ;
	root -> deleteTree( root ) ;
	return 0 ;
}