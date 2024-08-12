// https://leetcode.com/problems/next-greater-element-i/

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i] ) st.pop();
            if(!st.empty()) mp[nums2[i]]=nums2[st.top()]; 
            else mp[nums2[i]]=-1;
            st.push(i);
        }
        for(auto &x:nums1) x=mp[x];
        return nums1;    
    }
