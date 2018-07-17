// 1->2->3->4->5->6
// input : 2
// output : 5  Time complexity = O(n)

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

struct Node *nth_to_last(struct Node *head, int n){
	struct Node *curr = head, *prev = head ;

	for(int i = 0 ; i<n ; i++){
		if(curr != NULL)
			curr = curr->next ;
		else
			return NULL ;
	}

	while(curr != NULL){
		curr = curr->next ;
		prev = prev -> next ;
	}

	return prev ;
}

void print_list(struct Node *head){
	while(head != NULL){
		cout<<head->data<<" " ;
		head = head -> next ;
	}
	cout<<endl ;
}

int main(){
	int n ;
	Node *head = NULL ;

	head = insert_at_begining(head, 6) ;
	head = insert_at_begining(head, 5) ;
	head = insert_at_begining(head, 4) ;
	head = insert_at_begining(head, 3) ;
	head = insert_at_begining(head, 2) ;
	head = insert_at_begining(head, 1) ;
	head = insert_at_begining(head, -1) ;

	print_list(head) ;

	cout<<"\nEnter n : " ;
	cin>>n ;

	struct Node* temp = nth_to_last(head, n) ;
	if(temp)
		cout<<"Answer : "<<temp->data<<endl ;
	else
		cout<<"Sorry 'n' is larger then the size of linked list."<<endl ;
	return 0 ;
}
