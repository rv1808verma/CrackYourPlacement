// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

    bool isSafe(bool graph[101][101], vector<int> color_map, int v, int m, int n){
        for(int i=0; i<n; i++){
            if(graph[v][i] && color_map[i] == m) return false;
        }
        return true;
    }
    
    bool solve(bool graph[101][101], vector<int> color_map, int m, int n, int v){
        if(v==n) return true;
        for(int i = 1; i<=m; i++) {
            if(isSafe(graph, color_map, v, i, n)){
                color_map[v] = i;
                if(solve(graph, color_map, m, n, v+1))
                    return true;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color_map(n);
        return solve(graph, color_map, m, n, 0);
    }
