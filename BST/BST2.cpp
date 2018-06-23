/* Check wether the given binary tree is binary search tree or not ? */
#include <iostream>
#define MIN_VALUE -1000
#define MAX_VALUE 1000
using namespace std ;

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

bool isBinaryTreeUtil(node *root, int minvalue, int maxvalue){
	if(root == NULL)
		return true ;

	if(root->data < maxvalue && root->data > minvalue
		&& isBinaryTreeUtil(root->left, minvalue, root->data)
		&& isBinaryTreeUtil(root->right, root->data, maxvalue))
		return true ;
	else
		return false ;
	// return true if yes or false when not
}

void isBinaryTree(node *root){
	if(isBinaryTreeUtil(root, MIN_VALUE, MAX_VALUE))
		cout<<"\n Given tree is a Binary search tree "<<endl ;
	else
		cout<<"\n Given tree is not a Binary search tree "<<endl ;
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
	root = insert(root, 20) ;
	root = insert(root, 60) ;
	root = insert(root, 50) ;

	isBinaryTree(root) ;
	print_inorder(root) ;
	cout<<endl ;
	return 0 ;
}
