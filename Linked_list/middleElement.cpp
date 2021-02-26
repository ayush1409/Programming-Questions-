/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   
   if(head == NULL)
        return -1;
    
   struct Node *fast_ptr = head ;
   struct Node *slow_ptr = head ;
   //int cnt = 0 ;
   
   while(fast_ptr != NULL && fast_ptr->next != NULL){
        fast_ptr = fast_ptr->next->next ;
        slow_ptr = slow_ptr->next ;
        
        //cnt += 2 ;
   }
   /*
   if(fast_ptr == NULL){
        if(slow_ptr->next != NULL) 
            return slow_ptr->next->data ;
        else
            return slow_ptr->data ;
   }
    else
        return slow_ptr->data ;
    */
    
    if(slow_ptr != NULL)
        return slow_ptr -> data ;
    else 
        return -1 ;
}
