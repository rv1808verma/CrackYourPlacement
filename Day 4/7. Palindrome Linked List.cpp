// https://leetcode.com/problems/palindrome-linked-list/

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return 1;
        int cnt=0;
        ListNode* temp=head;
        while(temp){q
            cnt++;
            temp=temp->next;
        }
        cnt/=2;
        ListNode* curr=head, *prev=NULL;
        while(cnt){
            prev=curr;
            curr=curr->next;
            cnt--;
        }
        prev->next=NULL;
        prev=NULL;
        ListNode* fut=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        ListNode *temp1=head, *temp2=prev;
        while(temp1){
            if(temp1->val!=temp2->val) return 0;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 1;
    }


    ListNode* reverseLL(ListNode* head){
        ListNode* curr=head, *fut=NULL, *prev=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL) return true;
        ListNode* slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newHead=reverseLL(slow);
        ListNode *first=head;
        ListNode *second=newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverseLL(second);
                return 0;
            }
            first=first->next;
            second=second->next;
        }  
        reverseLL(second);
        return 1;
    }
