#include<iostream>
#include "bin_tree.cpp"
#include<vector>
using namespace std;

Node* uniqueTree( vector<int>& preorder , vector<int>& inorder , int& index , int inStart , int inEnd ) {
	if( inStart > inEnd )
		return nullptr ;
	
	Node* root = new Node( preorder[index++] ) ;
	int inRoot = inStart ;
	for( int i = inStart ; i <= inEnd ; i++ ) {
		if( root -> val == inorder[i] ) {
			inRoot = i ;
			break ;
		}
	}
	
	root -> left = uniqueTree( preorder , inorder , index , inStart , inRoot - 1 ) ;
	root -> right = uniqueTree( preorder , inorder , index , inRoot + 1 , inEnd ) ;
	return root ;
}

int main() {
	vector<int> preorder = {3,9,20,15,7} ;
	vector<int> inorder = {9,3,15,20,7} ;
	
	int i = 0 ;
	
	Tree t ;
	t.root = uniqueTree( preorder , inorder , i , 0 , inorder.size() - 1 ) ;
	t.levelOrder( ) ;
	return 0 ;
}