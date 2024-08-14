// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            int row=0,col=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) row++;
                if(mat[j][i]==1) col++;
            }
            if(row==n && col==n-1) return i;
        }
        return -1;
    }
