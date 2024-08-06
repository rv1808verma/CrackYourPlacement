// https://leetcode.com/problems/sum-of-distances-in-tree/

    void populateData(int par,int node,vector<vector<int>>&tree,vector<vector<int>>&data){
        for(auto child:tree[node]){
            if(child==par)continue;
            populateData(node,child,tree,data);
        }
        data[node][0]=0;
        data[node][1]=1;
        for(auto child:tree[node]){
            if(child==par)continue;
            data[node][0]+=(data[child][1]+data[child][0]);
            data[node][1]+=data[child][1];
        }
        return;
    }
    void solve(int par,int node,int n,vector<vector<int>>&tree,vector<vector<int>>&data){
        if(par!=-1){
            int nodesBelow=data[node][1]-1;
            int otherNodes=n-data[node][1]-1;
            data[node][0]=data[par][0]-nodesBelow+otherNodes;
        }
        for(auto child:tree[node]){
            if(child==par)continue;
            solve(node,child,n,tree,data);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<vector<int>> data(n,{0,0}); 
        populateData(-1,0,tree,data);
        solve(-1,0,n,tree,data);
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(data[i][0]);
        }
        return ans;
    }
