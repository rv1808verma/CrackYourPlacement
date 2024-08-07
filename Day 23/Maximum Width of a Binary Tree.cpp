// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
        
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty()){
            ll L=q.front().second;
            ll R=q.back().second;

            ans=max(ans,R-L+1);
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front().first;
                ll idx=q.front().second;
                q.pop();

                if(curr->left) q.push({curr->left, 2*idx+1});
                if(curr->right) q.push({curr->right, 2*idx+2});
            }
        }
        return ans;  
    }
