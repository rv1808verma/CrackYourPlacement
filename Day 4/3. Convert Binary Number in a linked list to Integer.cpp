// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

    int getDecimalValue(ListNode* head) {
        vector<int>tem;
        ListNode* temp=head;
        while(temp){
            tem.push_back(temp->val);
            temp=temp->next;
        }
        int n=tem.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=tem[n-i-1]*(pow(2,i));
        }
        return sum;
    }
