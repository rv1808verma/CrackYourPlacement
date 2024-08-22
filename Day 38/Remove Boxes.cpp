// https://leetcode.com/problems/remove-boxes/description/

int dp[100][100][100];
int removeBoxes(vector<int>& boxes) {

    memset(dp,0,sizeof(dp));
    
    int n=boxes.size();
    
    return helper(boxes,0,n-1,0);
}

    int helper(vector<int>&boxes,int i,int j,int k){
        if(i>j)return 0;
        if(dp[i][j][k]!=0) return dp[i][j][k];
    
        int res=(k+1)*(k+1)+helper(boxes,i+1,j,0);
    
        for(int range=i+1;range<=j;range++){  
            if(boxes[i]==boxes[range]){
                res=max(res,helper(boxes,i+1,range-1,0)+helper(boxes,range,j,k+1));
            }
        }
        return dp[i][j][k]=res;
    }
