// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* mergetwolists(Node* l1, Node*l2){
    if(!l1) return l2;
    if(!l2) return l1;
                                                                                                            // T.C:- O(N*N*M)
    Node* ans;                                                                                              // S.C:- Auxiliary - O(1) & O(N*M) becoz of recursion
    if(l1->data<l2->data){
        ans=l1;
        ans->bottom=mergetwolists(ans->bottom,l2);
    }else{
        ans=l2;
        ans->bottom=mergetwolists(l1,ans->bottom);
    }
    return ans;
}
    
Node *flatten(Node *root) {
    // Your code here
    if(root==NULL) return NULL;
    
    Node *head2=flatten(root->next);
    return mergetwolists(root,head2);
}
