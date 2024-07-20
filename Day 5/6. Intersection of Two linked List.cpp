// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mp;
        ListNode* temp1=headA;
        while(temp1){
            mp[temp1]++;
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        while(temp2){
            mp[temp2]++;
            temp2=temp2->next;
        }
        for(auto it: mp){
            if(it.second>1){
                return it.first;
                break;
            }
        }
        return NULL;
    }

   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2) return temp1;

            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;    
    }
