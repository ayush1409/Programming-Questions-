#include <iostream>
using namespace std ;

struct node{
	int data ;
	node *left, *right ;
} ;

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

int findMax(node *root){
	if(root == NULL)
		return -1 ;
	while(root->right != NULL){
		root = root->right ;
	}
	return root->data ;
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
	int choice,x, max ;
	node *min ;
	while(1){
		cout<<" Enter choice\n 1: Insert element\n 2: Find Min\n 3: Find Max\n 4: Print Inorder traversal\n 5: Delete node \n 0: Exit\n " ;
		cin>>choice ;
		switch (choice) {
			case 1 : 	cout<<"\n Enter value : " ;
						cin>>x ;
						root = insert(root, x) ;
						cout<<endl ;
						break ;

			case 2 : 	min = findMin(root) ;
						if(min != NULL)
							cout<<"\n Minimum Value : "<<min->data<<endl ;
						else
							cout<<"Sorry the tree is empty."<<endl ;
						break ;

			case 3 : 	max = findMax(root) ;
						if(max != -1)
							cout<<"\n Maximum Value : "<<max<<endl ;
						else
							cout<<"Sorry the tree is empty."<<endl ;
						break ;

			case 4 : 	print_inorder(root) ;
						cout<<endl ;
						break ;

			case 5 :	cout<<"Enter value of node to be deleted : " ;
						cin>>x ;
						root = delete_node(root ,x) ;
						break ;

			default : 	if(choice != 0)
							cout<<"Please enter right choice." ;
						break ;
		}
		if(choice == 0)
			break ;
	}
	cout<<endl ;
	return 0 ;
}
