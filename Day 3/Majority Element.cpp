// https://leetcode.com/problems/majority-element/

    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int temp=n/2;
        map<int,int>mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;  
        for(auto it:mp){
            if(it.second>temp){
                return it.first;
                break;
            }
        }
        return -1;
    }
