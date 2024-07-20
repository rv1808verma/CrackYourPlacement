// https://leetcode.com/problems/merge-two-sorted-lists/description/

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* ans;
        if(list1->val<list2->val){
            ans=list1;
            ans->next=mergeTwoLists(ans->next,list2);
        }else{
            ans=list2;
            ans->next=mergeTwoLists(list1,ans->next);
        }
        return ans;
    }
