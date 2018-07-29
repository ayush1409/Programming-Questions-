/* Find the lowest common ansestor in the given Binary search tree*/
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

node* find_lowest_common_ansestor(node *root,int data1, int data2){
	if(root->data > max(data1, data2))
		root->left = find_lowest_common_ansestor(root->left, data1, data2) ;
	else if(root->data < max(data1, data2))
		root->right = find_lowest_common_ansestor(root->right, data1, data2) ;
	else
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
	int data1, data2 ;
	node *root = NULL ;
	root = insert(root, 40) ;
	root = insert(root, 10) ;
	root = insert(root, 5) ;
	root = insert(root, 20) ;
	root = insert(root, 60) ;
	root = insert(root, 50) ;
	cout<<"\nInorder traversal : " ;
	print_inorder(root) ;
	cout<<"\n enter the value n1 n2 (value of the two nodes): " ;
	cin>>data1>>data2 ;
	//node *node1 = find_node(root, data1) ;
	//node *node2 = find_node(root, data2) ;
	node *temp =  find_lowest_common_ansestor(root,data1,data2) ;
	cout<<"LCA : "<<temp->data<<endl ;
	return 0 ;
}
