// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* temp=head, *prev=dummy;
        while(temp){
            if(temp->next!=NULL && temp->val==temp->next->val){
                while(temp->next!=NULL && temp->val==temp->next->val){
                    temp=temp->next;
                } 
                prev->next=temp->next;
            }else{
                prev=prev->next;
            }
            temp=temp->next;
        }    
        return dummy->next;
    }
