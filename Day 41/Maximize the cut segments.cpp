// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

    int dp[10001];
    int rec(int n,vector<int>&arr){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int temp=INT_MIN;
        for(int i=0;i<3;++i){
            temp=max(temp,1+rec(n-arr[i],arr));
        }
        return dp[n]=temp;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        vector<int>arr={x,y,z};
        int ans=rec(n,arr);
        return ans<0?0:ans;
    }
