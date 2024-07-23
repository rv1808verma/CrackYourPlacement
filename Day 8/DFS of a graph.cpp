// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
    // Code here
        vector<bool> visited(V, 0);
        vector<int> ans;
        DFS(0, adj, visited, ans);
        return ans;
    }
