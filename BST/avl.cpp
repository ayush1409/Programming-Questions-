/*Balanced Binary Search Tree*/
#include <iostream>
using namespace std ;

struct Node {
	int data, height=0 ;
	Node *left, *right, *parent ;
};
// create node
struct Node *create_node(struct Node *parent,int data){
	Node *node = new Node() ;
	node->data = data ;
	node->left = node->right = NULL ;
	node->parent = parent ;
	return node ;
}
// Time : O(1)
int find_slope(struct Node *root){
	int slope ;

	if(root->left != NULL && root->right != NULL)
		slope = (root->left->height) - (root->right->height) ;
	else if(root->left != NULL)
		slope = root->left->height ;
	else if(root->right != NULL)
		slope = -(root->right->height) ;
	else
		slope = 0 ;

	return slope ;
}

// Time : O(1)
struct Node *rotate_left(struct Node *root){
	int x = root->data ;
	int y = root->right->data ;
	Node *tl = root->left ;
	Node *trl = root->right->left ;
	Node *trr = root->right->right ;

	root->data = y ;
	root->left = root->right ;
	root->left->data = x ;
	root->right = trr ;
	root->left->right = trl ;
	root->left->left = tl ;

	return root ;
}

// Time : O(1)
struct Node *rotate_right(struct Node *root){
	int x = root->data ;
	int y = root->left->data ;
	Node *tll = root->left->left ;
	Node *tlr = root->left->right ;
	Node *tr = root->right ;

	root->data = y ;
	root->right = root->left ;
	root->right->data = x ;
	root->left = tll ;
	root->right->left = tlr ;
	root->right->right = tr ;

	return root ;
}

// Balance tree, Time : O(logn)
struct Node *rebalance(struct Node *root){
	int slope_x = find_slope(root) ;
	int slope_y ;

	if(slope_x == 2){
		if(find_slope(root->left) == -1)
			root->left = rotate_left(root->left) ;
		root = rotate_right(root) ;
	}
	else if(slope_x == -2){
		if(find_slope(root->right) == -1)
			root->right = rotate_right(root->right) ;
		root = rotate_left(root) ;
	}

	return root ;
}

//insert node Time : O(logn)
struct Node *insert(struct Node *root, struct Node *parent, int data){
	if(root == NULL){
		root = create_node(parent, data) ;
	}
	else if(root->data > data){
		root->left = insert(root->left, root, data) ;
		root->left = rebalance(root->left) ;
	}
	else if(root->data<data){
		root->right = insert(root->right, root, data) ;
		root->right = rebalance(root->right) ;
	}
	// update height
	if(root->left != NULL && root->right != NULL)
		root->height = 1 + max(root->left->height, root->right->height) ;

	return root ;
}

void print_inorder(struct Node *root){
	if(root != NULL){
		print_inorder(root->left) ;
		cout<<root->data<<" " ;
		print_inorder(root->right) ;
	}
}

int main(){
	Node *root = NULL ;
	root = insert(root, NULL, 5);
	root = insert(root, NULL, 4);
	root = insert(root, NULL, 3);
	root = insert(root, NULL, 2);
	root = insert(root, NULL, 1);

	cout<<"Inorder Traversal : " ;
	print_inorder(root) ;
	cout<<endl ;
	return 0 ;
}
