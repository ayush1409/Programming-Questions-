#include <iostream>
#include <vector>
using namespace std ;

struct Node{
	int data ;
	int leftindex, rightindex ;
	Node(int data, int leftindex, int rightindex) : data(data), leftindex(leftindex), rightindex(rightindex) {}
} ;

class binary_tree{
	vector<struct Node> bt;
public:
	void makeNode(int data) ;
	void insert(int data) ;
	void insertLeft(int index, int data) ;
	void insertRight(int index, int data) ;
	void traverse(int index, int order) ;
	int height(int index) ;
} ;

void binary_tree::makeNode(int data){
	struct Node b = {data,-1,-1} ;
	bt.push_back(b) ;
}

void binary_tree::insertLeft(int index, int data){
	struct Node b = {data, -1, -1} ;
	bt[index].leftindex = bt.size() ;
	bt.push_back(b) ;
}

void binary_tree::insertRight(int index, int data){
	struct Node b = {data, -1, -1} ;
	bt[index].rightindex = bt.size() ;
	bt.push_back(b) ;
}

void binary_tree::insert(int data){

	// when the tree is empty 
	if(bt.size() == 0){
		makeNode(data) ;
	}
	
	// when the tree is non-empty
	else{

		int index = 0 ;
		while(index<bt.size()) {
		
		// either insert on left
			if(bt[index].data > data){
				if(bt[index].leftindex == -1){
					insertLeft(index,data) ;
					break ;
				}
				else
					index = bt[index].leftindex ;
			}

		// or insert at right
			else{
				if(bt[index].rightindex == -1){
					insertRight(index,data) ;
					break ;
				}
				else
					index = bt[index].rightindex ;
			}
			
		}
	}
}

void binary_tree::traverse(int index, int order){
	if(order == 1)
		cout<<bt[index].data<<" " ;
	
	if(bt[index].leftindex != -1)
		traverse(bt[index].leftindex, order) ;

	if(order == 2)
		cout<<bt[index].data<<" " ;

	if(bt[index].rightindex != -1)
		traverse(bt[index].rightindex, order) ;

	if(order == 3)
		cout<<bt[index].data<<" " ;
}

int binary_tree::height(int index){

	// base condition : height of leaf is 0
	if(bt[index].leftindex == -1 && bt[index].rightindex == -1)
		return 0 ;

	int leftheight = 0 ;
	if(bt[index].leftindex != -1)
		leftheight = height(bt[index].leftindex) ;

	int rightheight = 0 ;
	if(bt[index].rightindex != -1)
		rightheight = height(bt[index].rightindex) ;

	if(leftheight <= rightheight)
		return rightheight + 1 ;
	else
		return leftheight + 1 ;
}


int main(){
	binary_tree b1 ;

	b1.insert(60); b1.insert(40); b1.insert(20); b1.insert(25); b1.insert(90);
	b1.insert(23); b1.insert(95); b1.insert(80); b1.insert(85);
	

	
	cout<<"\nPreoder-------------------------------------------------------"<<endl ;
	b1.traverse(0,1) ;

	
	cout<<"\nInorder-------------------------------------------------------"<<endl ;
	b1.traverse(0,2) ;

	
	cout<<"\nPostorder-------------------------------------------------------"<<endl ;
	b1.traverse(0,3) ;
	
	cout<<"\nTree height : "<<b1.height(0)<<endl ;

	cout<<endl ;
	return 0 ;
} 