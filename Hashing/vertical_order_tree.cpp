#include <iostream>
#include <map>
#include <vector>
using namespace std ;

struct Node {
	int data ;
	Node *left, *right ;
};

struct Node* newNode(int data){
	Node *temp = new Node() ;
	temp -> data = data ;
	temp->left = temp->right = NULL ;
	return temp ;
}
void find_virtical_order(Node *root, int hd, map<int, vector<int>> &m){
	if(root==NULL)
		return ;

	m[hd].push_back(root->data) ;

	find_virtical_order(root->left, hd-1, m) ;

	find_virtical_order(root->right, hd+1, m) ;
}

void print_vertical_order(Node *root){

	map<int, vector<int>> m ;
	int hd=0 ;

	find_virtical_order(root, hd, m) ;

	for(auto it=m.begin() ; it!=m.end() ; it++){
		for(int i=0 ; i<(it->second).size() ; ++i)
			cout<<it->second[i]<<" " ;
		cout<<endl ;
	}
}

int main(){
	Node *root = newNode(1) ;
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);

	print_vertical_order(root) ;

	return 0 ;
}
