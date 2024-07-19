// https://leetcode.com/problems/reverse-linked-list/

    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head, *prev=NULL, *fut=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }     
        return prev;
    }
