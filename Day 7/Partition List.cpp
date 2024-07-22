// https://leetcode.com/problems/partition-list/

    ListNode* partition(ListNode* head, int x) {
        ListNode* small= new ListNode(-1);
        ListNode* dummy=small;
        ListNode* large= new ListNode(-1);
        ListNode* dummy1=large;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                small->next=temp;
                small=small->next;
            }else{
                large->next=temp;
                large=large->next;
            }
            temp=temp->next;
        }
        large->next=NULL;
        small->next=dummy1->next;
        return dummy->next;
    }
