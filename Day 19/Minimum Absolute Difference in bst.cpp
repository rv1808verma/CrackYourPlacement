// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

    void inorder(TreeNode* root, vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int ans=abs(v[0]-v[1]);
        for(int i=2;i<v.size();i++)
        {
            ans=min(ans,abs(v[i]-v[i-1]));
        }
        return ans;
    }
