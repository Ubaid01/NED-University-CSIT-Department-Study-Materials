#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

struct Node {
	int val ;
	Node* left ;
	Node* right ;
	Node( int val ) : val( val ) , left( nullptr ) , right( nullptr ) {}	
	
	void deleteTree( Node* node ) {
		if( node ) {
			deleteTree( node -> left ) ;
			deleteTree( node -> right ) ;
			delete node ;
		}
	}
} ;

Node* convertTree( vector<int>& inorder , int inStart , int inEnd ) {
	if( inStart > inEnd )
		return nullptr ;
	
	if( inStart == inEnd )
		return new Node( inorder[inEnd ] ) ;
	
	int mid = inStart + ( inEnd - inStart + 1 ) / 2 ; // For answer a/c to question ; else can avoid if( inStart == inEnd ) and also +1.
	Node* root = new Node( inorder[mid] ) ;
	root -> left = 	convertTree( inorder , inStart , mid - 1 ) ;
	root -> right = convertTree( inorder , mid + 1 , inEnd ) ;
	return root ;
}

void levelOrder(Node* root) {
    if (!root) 
		return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
		if( !node ) {
			cout << "nullptr " ;
			continue;
		}

        cout << node -> val << " ";
        // if ( node -> left ) 
		q.push( node -> left ) ;
        // if ( node -> right ) 
		q.push( node -> right ) ;
    }
    cout << endl;
}

int main() {
	vector<int> inorder = {-10,-3,0,5,9} ;
	Node* root = convertTree( inorder , 0 , inorder.size() - 1 ) ;
	levelOrder( root ) ;
	root -> deleteTree( root ) ;
	return 0 ;
}