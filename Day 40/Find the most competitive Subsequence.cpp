// https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>arr;
        int i=0;
        for(;i<n-k;i++){
            arr.push({nums[i],i});
        }
        vector<int>ans;
        int ci=-1;
        for(;i<n;i++){
            arr.push({nums[i],i});
            while(arr.top()[1]<ci)arr.pop();
            ans.push_back(arr.top()[0]);
            ci=arr.top()[1];
            arr.pop();
        }
        return ans;   
    }
