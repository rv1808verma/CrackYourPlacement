// https://leetcode.com/problems/reverse-nodes-in-k-group/

    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL, *curr=head;
        while(curr!=NULL){
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }                                                                                  // T.C:- O(2N) & S.C:- O(1)

    ListNode* getkthnode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast) prevlast->next=temp;
                break;
            } 
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reverseList(temp);
            if(temp==head) head=kthnode;
            else prevlast->next=kthnode;

            prevlast=temp;
            temp=nextnode;
        }
        return head;
    }
