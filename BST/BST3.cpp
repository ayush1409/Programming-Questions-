
/* Deleting node from binarty search tree */
#include <iostream>
using namespace std;
struct node{
	int data ;
	node *left, *right ;
};

node* getNewNode(int data){
	node *tmp = new node();
	tmp->data = data ;
	tmp->left = tmp->right = NULL ;
	return tmp ;
}

node* insert(node *root, int data){
	if(root == NULL){
		root = getNewNode(data) ;
	}
	else if(data <= root->data){
		root->left = insert(root->left, data) ;
	}
	else {
		root->right = insert(root->right, data) ;
	}
	return root ;
}

node* findMin(node *root){
	if(root == NULL)
		return root ;
	while(root->left != NULL){
		root = root->left ;
	}
	return root ;
}

node* delete_node(node *root, int data){

	if(root == NULL)
		return root ;
	if(data < root->data) delete_node(root->left, data) ;
	else if(data > root->data) delete_node(root->right, data) ;
	else{

		// case 1: no child
		if(root->left == NULL && root->right == NULL){
			delete root ;
			root = NULL ;
		}

		// case 2: single child
		else if(root->right == NULL){
			node *temp = root ;
			root = root->left ;
			delete temp ;
		}
		else if(root->left == NULL){
			node *temp = root ;
			root = root->right ;
			delete temp ;
		}

		// case 3: 2 child
		else{
			node *temp = findMin(root->right) ;
			root->data = temp->data ;
			root->right = delete_node(root->right, temp->data);
		}
	}
	return root ;
}

void print_inorder(node *root){
	if(root != NULL){
		print_inorder(root->left) ;
		cout<<" "<<root->data ;
		print_inorder(root->right) ;
	}
}

int main(){
	node *root = NULL ;
	root = insert(root, 40) ;
	root = insert(root, 10) ;
	root = insert(root, 5) ;
	root = insert(root, 20) ;
	root = insert(root, 60) ;
	root = insert(root, 50) ;
	print_inorder(root) ;
	cout<<endl ;
	root = delete_node(root, 10) ;
	print_inorder(root) ;
	cout<<endl ;
	root = delete_node(root, 5) ;
	print_inorder(root) ;
	cout<<endl ;
	return 0 ;
}
