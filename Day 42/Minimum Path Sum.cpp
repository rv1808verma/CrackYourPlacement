// https://leetcode.com/problems/minimum-path-sum/description/

int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i==0&&j==0)return grid[0][0];
    if(i<0||j<0)return INT_MAX;
    int up=solve(i-1,j, grid,dp);
    int left=solve(i,j-1, grid,dp);
    return grid[i][j]+min(up,left);

}

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);

        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
            
                if(i==0&&j==0)temp[j]=grid[i][j];
                else{
                int up=grid[i][j];
                if(i>0)up+=dp[j];
                else up+=1e9;
                int left=grid[i][j];
                if(j>0)left+=temp[j-1];
                else left+=1e9;
                temp[j]=min(up,left);
                }
            }
            dp=temp;
        }
        return dp[m-1];    
    }
