// https://www.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

    Node* zigZag(Node* head) {
        // your code goes here
        if(!head || !head->next) return head;
        Node *curr = head;
        bool flag = true;
        while(curr->next != NULL)
        {
            if(flag){
                if(curr->data > curr->next->data){
                    swap(curr->data,curr->next->data);
                }
            }
            else{
                if(curr->data < curr->next->data){
                    swap(curr->data, curr->next->data);
                }
            }
            curr=curr->next;
            flag=!flag;
        }
        return head;
    }
