#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int val ;
	Node* left ;
	Node* right ;
	Node( int val ) : val(val) , left(nullptr) , right(nullptr) {}
} ;

class Tree { 
private:
	 void inorderTraversal(Node* node) {
		 if (node == nullptr) return;
		 inorderTraversal(node->left);
		 cout << node->val << " ";
		 inorderTraversal(node->right);
	}

	void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
		root = nullptr ;
    }
}
public:
 	Node* root;
 	Tree() {
		 root = nullptr;
	}
	
	void levelOrder( ) {
		if( !root )
			return ;
		
		queue<Node*> q ;
		q.push( root ) ;
		while( !q.empty() ) {
			Node* cur = q.front() ;
			q.pop() ;
			
			cout << cur -> val << " " ;
			if( cur -> left )
				q.push( cur -> left );
			if( cur -> right )
				q.push( cur -> right ) ;
		}
		cout << endl ;
	}
	 void insert(int data) { 
		 Node* newNode = new Node(data);
		 if (root == nullptr) {
			 root = newNode;
			 return;
	 	}
		 queue<Node*> q;
		 q.push(root);
		 while (!q.empty()) {
		 Node* current = q.front();
		 q.pop();
		 if (current->left == nullptr) {
			 current->left = newNode;
			 return;
		 }
		else {
		 	q.push(current->left);
		}

		if (current->right == nullptr) {
			 current->right = newNode;
			 return;
		 } 
		 else {
		 	q.push(current->right);
 			}
 		}
 	}
	 void inorder() { 
	 inorderTraversal(root);
	 	cout << endl;
	}

	~Tree() {
		deleteTree( root ) ;
	}
} ;