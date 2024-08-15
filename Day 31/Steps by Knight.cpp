// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
        int x1=KnightPos[0]-1;
        int y1=KnightPos[1]-1;
        int x2=TargetPos[0]-1;
        int y2=TargetPos[1]-1;
        
        vector<vector<int>> vis(N,vector<int> (N,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{x1,y1},0});
        vis[x1][y1]=1;
        
        
        int drow[]={1,2,2,1,-1,-2,-2,-1};
        int dcol[]={2,1,-1,-2,-2,-1,1,2};
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;

            if(row==x2 && col==y2){
                   return steps;
            }
            q.pop();
            
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<N && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        return -1;
	}
