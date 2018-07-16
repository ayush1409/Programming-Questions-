#include <iostream>
using namespace std ;

struct Node{
	int data ;
	Node *next ;
} ;

struct Node* create_node(int data){
	Node *temp = new Node() ;
	temp -> data = data ;
	temp -> next = NULL ;
	return temp ;
}

struct Node* insert_at_begining(struct Node *head, int data){
	Node *temp = create_node(data) ;

	if(head == NULL){
		head = temp ;
		return head ;
	}

	temp -> next = head ;
	head = temp ;
	return head ;
}

// create a function that swaps the nodes not data
struct Node* swap(struct Node *head, int p, int q){
	Node *prev_x = NULL, *prev_y = NULL, *x = head, *y = head ;

	while(x && x->data != p){
		prev_x = x ;
		x = x->next ;
	}
	while(y && y->data != q){
		prev_y = y ;
		y = y->next ;
	}
	if(x->next == NULL && x-> data != p)
		return NULL ;
	if(y->next == NULL && y-> data != q)
		return NULL;

	if(prev_x != NULL)
		prev_x -> next = y ;
	else
		head = y ;

	if(prev_y != NULL)
		prev_y -> next = x ;
	else
		head = x ;

	Node *temp = x->next ;
	x->next = y->next ;
	y ->next = temp ;

	return head ;

}

void print_list(struct Node *head){
	while(head != NULL){
		cout<<head->data<<" " ;
		head = head -> next ;
	}
	cout<<endl ;
}

int main(){
	Node *head = NULL ;

	head = insert_at_begining(head, 15 ) ;
	head = insert_at_begining(head, 22 ) ;
	head = insert_at_begining(head, 12 ) ;
	head = insert_at_begining(head, 19 ) ;
	head = insert_at_begining(head, 11 ) ;
	head = insert_at_begining(head, 39 ) ;
	print_list(head) ;

	head = swap(head, 15, 11);

	if(head != NULL)
		print_list(head) ;

	return 0 ;
}
