// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inDeg(V, 0);
        for (int i = 0; i < V; i++){
            for (int j = 0; j < adj[i].size(); j++){
                inDeg[adj[i][j]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!inDeg[i]) q.push(i);
            int count = 0;

            while (!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for (int i = 0; i < adj[node].size(); i++){
                inDeg[adj[node][i]]--;
                if (!inDeg[adj[node][i]]) q.push(adj[node][i]);
            }
        }
        return count != V;
    }
