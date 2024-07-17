// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()) cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }

// yt refer video:- https://www.youtube.com/watch?v=7Xeorb721LQ&themeRefresh=1
