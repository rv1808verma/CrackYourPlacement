// https://leetcode.com/problems/flood-fill/description/

    void dfs(int i,int j,vector<vector<int>>& image,int hunt,int color)
    {
        if(color==hunt)
        return;
        if(i<0||j<0||i==image.size()||j==image[0].size()||image[i][j]!=hunt)
        return;
        image[i][j]=color;
        dfs(i+1,j,image,hunt,color);
        dfs(i-1,j,image,hunt,color);
        dfs(i,j+1,image,hunt,color);
        dfs(i,j-1,image,hunt,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int hunt=image[sr][sc];
        dfs(sr,sc,image,hunt,color);
        return image;   
    }
