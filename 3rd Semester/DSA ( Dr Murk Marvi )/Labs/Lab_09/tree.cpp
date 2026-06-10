#include <iostream>
using namespace std;

struct Node {
 int val;
 Node* left;
 Node* right;
 Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
	 Node* root;
	 BST() : root(nullptr) {}
	 void insert(int key) {
	 	root = insertRec(root, key);
	 }
	 void deleteNode(int key) {
	 	root = deleteRec(root, key);
	 }
	 void inorder() {
	 	inorderRec(root);
	 	cout << endl;
	 }
	 ~BST(){
	 	deleteChild(root) ;
	 }
private:
	 // Recursive function to insert a node
	 Node* insertRec(Node* node, int key) {
		 // Base case: if the tree is empty, create a new node
		 if (node == nullptr)
		 	return new Node(key);
		 // Otherwise, recur down the tree
		 if (key < node->val)
		 	node->left = insertRec(node->left, key);
		 else if (key > node->val)
		 	node->right = insertRec(node->right, key);
		 return node;
	 }
	 // Recursive function to delete a node
	 Node* deleteRec(Node* node, int key) {
		 // Base case: if the tree is empty
		 if (node == nullptr)
		 	return node;
		 // Recur down the tree
		 if (key < node->val)
		 	node->left = deleteRec(node->left, key);
		 else if (key > node->val)
		 	node->right = deleteRec(node->right, key);
		 else {
		 // Node with only one child or no child
		 	if (node->left == nullptr) {
				 Node* temp = node->right;
				 delete node;
		 		return temp;
		 	} 
		 	else if (node->right == nullptr) {
				 Node* temp = node->left;
				 delete node;
				 return temp;
	 		}
		 // Node with two children: Get the inorder successor (smallest in the right subtree)
		 Node* temp = minValueNode(node->right);
		 // Copy the inorder successor's content to this node
		 node->val = temp->val;
		 // Delete the inorder successor
		 node->right = deleteRec(node->right, temp->val);
		 }
		 return node;
	 }
 	// Find the node with the minimum value (used for deleting nodes)
	 Node* minValueNode(Node* node) {
		 Node* current = node;
		 while (current && current->left != nullptr)
			 current = current->left;
			 return current;
		 }
 	// Inorder traversal function
	 void inorderRec(Node* root) {
		 if (root != nullptr) {
			 inorderRec(root->left);
			 cout << root->val << " ";
			 inorderRec(root->right);
		 }
	 }
	 
	 void deleteChild( Node* root ) {
	 	if( root ) {
	 		deleteChild( root -> left ) ;
	 		deleteChild( root -> right ) ;
	 		delete root ;
	 		root = nullptr ;
		 }
	 }
};
