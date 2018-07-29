/*
	given a binary tree and a value 'x'
	we have to find wether there is a path from root to leaf such that the sum of nodes
	within the path is equal to x
*/
#include <iostream>
#include <vector>
using namespace std ;

struct Node{
	int data ;
	Node *left, *right ;
} ;

Node* create_node(int data){
	Node *node = new Node() ;
	node->data = data ;
	node->left = NULL ;
	node->right = NULL ;
	return node ;
}

bool root_to_leaf(Node *root, int sum, vector<int> &path_nodes){
	if(root == NULL)
		return false ;
	if(root->left == NULL && root->right == NULL){
		if(sum == root->data){
			path_nodes.push_back(root->data) ;
			return true ;
		}
		else
			return false ;
	}

	if(root_to_leaf(root->left, sum-(root->data), path_nodes)){
		path_nodes.push_back(root->data) ;
		return true  ;
	}
	if(root_to_leaf(root->right, sum-(root->data), path_nodes)){
		path_nodes.push_back(root->data) ;
		return true  ;
	}

}

int main(){
	vector<int> path_nodes ;
	Node *root = create_node(10) ;
	root->left = create_node(16) ;
	root->right = create_node(5) ;
	root->left->right = create_node(-3) ;
	root->right->left = create_node(6) ;
	root->right->right = create_node(11) ;

	bool result = root_to_leaf(root,26,path_nodes) ;
	if(result)
		cout<<"\n Path exists"<<endl ;
	else
		cout<<"\n Path does not exist"<<endl ;

	return 0 ;
}
