// https://leetcode.com/problems/as-far-from-land-as-possible/

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visit;

        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    visit.insert({i, j});
                }
            }
        }

        vector<vector<int>> direc = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int len = 0;

        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();

                for (auto dir: direc){
                    int r = curr.first + dir[0];
                    int c = curr.second + dir[1];

                    if (min(r, c) < 0 || max(r, c) >= grid.size() || grid[r][c] == 1 || visit.find({r, c}) != visit.end())
                        continue;
                    
                    visit.insert({r, c});
                    q.push({r, c});
                }
            }
            len++;
        }
        return (len - 1 != 0 ? len - 1 : -1);
    }
