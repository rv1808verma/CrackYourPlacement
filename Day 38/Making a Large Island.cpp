// https://leetcode.com/problems/making-a-large-island/description/

   void calculateArea(int i, int j, int label, int& area, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        if(grid[i][j] != 1) return;
        grid[i][j] = label;
        area++;
        calculateArea(i-1, j, label, area, grid);
        calculateArea(i, j-1, label, area, grid);
        calculateArea(i+1, j, label, area, grid);
        calculateArea(i, j+1, label, area, grid);
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> island;
        int area = 0;
        int maxArea = 0;
        int islandLabel = 2;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    area = 0;
                    calculateArea(i, j, islandLabel, area, grid);
                    island[islandLabel] = area;
                    islandLabel++;
                }              
            }
        }
        
        if(island.size() == 0) return 1;
        maxArea = island.begin()->second;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    vector<int> proccessed;
                    area = 1;
                    if(i > 0 && grid[i-1][j] > 1)
                    {
                        proccessed.push_back(grid[i-1][j]);
                        area += island[grid[i-1][j]];
                    }
                    if(j > 0 && grid[i][j-1] > 1 && find(proccessed.begin(), proccessed.end(), grid[i][j-1]) == proccessed.end())
                    {
                        proccessed.push_back(grid[i][j-1]);
                        area += island[grid[i][j-1]];
                    }
                    if(i < grid.size()-1 && grid[i+1][j] > 1 && find(proccessed.begin(), proccessed.end(), grid[i+1][j]) == proccessed.end())
                    {
                        proccessed.push_back(grid[i+1][j]);
                        area += island[grid[i+1][j]];
                    }
                    if(j < grid[0].size()-1 && grid[i][j+1] > 1 && find(proccessed.begin(), proccessed.end(), grid[i][j+1]) == proccessed.end())
                    {
                        area += island[grid[i][j+1]];
                    }
                    maxArea = max(maxArea, area);
                }              
            }
        }
        return maxArea;  
    }
