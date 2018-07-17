/*
	input : 1->2->3->4
	output : 1->2 and 3->4
	input : 1->2->3->4->5
	output : 1->2->3 and 4->5
*/

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

void print_list1(struct Node *head, struct Node *prev){
	while(head != prev){
		cout<<head->data<<" " ;
		head = head -> next ;
	}
	cout<<endl ;
}
void print_list2(struct Node *second){
	while(second != NULL){
		cout<<second->data<<" " ;
		second = second -> next ;
	}
	cout<<endl ;
}

struct Node *split_list(struct Node *head){
	struct Node *curr = head, *prev = head ;

	while(curr!=NULL){
		if(curr->next == NULL)
			return prev->next ;
		curr = curr->next->next ;
		prev = prev -> next ;
	}

	return prev ;
}

int main(){
	Node *head = NULL ;

	head = insert_at_begining(head, 6) ;
	head = insert_at_begining(head, 5) ;
	head = insert_at_begining(head, 4) ;
	head = insert_at_begining(head, 3) ;
	head = insert_at_begining(head, 2) ;
	head = insert_at_begining(head, 1) ;
	head = insert_at_begining(head, -1) ;
	struct Node *second = split_list(head) ;

	print_list1(head, second) ;
	print_list2(second) ;

	return 0 ;
}
