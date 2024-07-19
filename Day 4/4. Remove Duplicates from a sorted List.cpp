// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }
        }
        temp=head;
        return temp;
    }
