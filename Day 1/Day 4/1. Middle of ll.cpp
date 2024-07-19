// https://leetcode.com/problems/middle-of-the-linked-list/

    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        cnt/=2;
        while(cnt){
            temp=temp->next;
            cnt--;
        }
        return temp;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
