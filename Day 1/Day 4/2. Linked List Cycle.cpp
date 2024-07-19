// https://leetcode.com/problems/linked-list-cycle/

    bool hasCycle(ListNode *head) {
        map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return true;
                break;
            }
            mp[temp]++;
            temp=temp->next;
        }  
        return false;
    }

    bool hasCycle(ListNode *head) {
        ListNode* slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
