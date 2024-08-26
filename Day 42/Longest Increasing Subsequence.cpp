// https://leetcode.com/problems/longest-increasing-subsequence/

    int fun(int ind,int prev,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    
        int len= 0+fun(ind+1,prev,n,nums,dp); //not take
        if(prev ==-1 || nums[ind]>nums[prev]){ //take
            len= max(len,1+ fun(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prev+1]= len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,-1,n,nums,dp);    
    }
