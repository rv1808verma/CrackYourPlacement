// https://leetcode.com/problems/add-two-numbers/

    ListNode* reverse(ListNode* head){
        ListNode* curr=head, *prev=NULL, *fut=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(l1!=NULL || l2!=NULL || carry){
            sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            sum=sum%10;
            
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        return dummy->next;
    }
