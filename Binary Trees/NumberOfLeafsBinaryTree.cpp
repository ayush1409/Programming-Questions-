
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
   
void inorder(Node *root, int *count_ptr){
    
    if(root == NULL)
        return ; 
    
    if(root->left == NULL && root->right == NULL)
        *count_ptr += 1 ;
    
    else if(root != NULL){
        inorder(root->left, count_ptr) ;
        inorder(root->right, count_ptr) ;
    }
}

int countLeaves(Node* root)
{
    int count = 0 ;
    int *count_ptr = &count ;
    inorder(root,count_ptr) ; 
    
    return count ;
  // Your code here
}
