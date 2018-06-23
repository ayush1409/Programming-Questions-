/* Find the inorder successor of given node */
#include <iostream>
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

node* find_node(node *root, int data){
	if(root == NULL)
		return NULL ;
	if(root->data == data)
		return root ;
	if(root->data > data)
		find_node(root->left, data) ;
	else
		find_node(root->right, data) ;
}

node* findmin(node *root){
	if(root == NULL)
		return root ;
	while(root->left != NULL){
		root = root->left ;
	}
	return root ;
}

node* getInorderSuccessor(node *root, int data){
	if(root == NULL)
		return root ;
	node *current = find_node(root,data) ;
	// case 1 : if the right subtree is not empty
	if(current->right != NULL) {
		return findmin(current->right);
	}
	// case 2 : if the right subtree is empty
	// we need to find the deepest ansestor which has current in it's left subtree
	else{
		node *ansestor = root ;
		node *successor = NULL ;
		while(current != ansestor){
			if(current -> data < ansestor -> data){
				successor = ansestor ;
				ansestor = ansestor -> left ;
			}
			ansestor = ansestor -> right;
		}
		return successor ;
	}
}

int main(){
	node *root = NULL ;
	root = insert(root, 40) ;
	root = insert(root, 10) ;
	root = insert(root, 20) ;
	root = insert(root, 60) ;
	root = insert(root, 50) ;
	node *successor = getInorderSuccessor(root,20) ;
	cout<<"successor of 20 is "<<successor->data<<endl ;
	return 0 ;
}
