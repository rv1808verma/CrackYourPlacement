// https://leetcode.com/problems/number-of-islands/

   int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> drs{-1, 0, 1, 0, -1};
        int ans = 0;

        function<void(int,int)> solve = [&](int i, int j){
            if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0') return;
            grid[i][j] = '0';

            for(int k = 0; k < 4; k++){
                int nx = i + drs[k], ny = j + drs[k + 1];
                solve(nx, ny);
            }
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '0') continue;
                ans++;
                solve(i, j);
            }
        }

        return ans;   
    }
