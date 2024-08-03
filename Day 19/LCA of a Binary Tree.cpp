// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        int curr=root->val;

        if(curr<p->val&&curr<q->val) // If both of them lie on the right
        return lowestCommonAncestor(root->right,p,q);

        if(curr>p->val&&curr>q->val) // If both of them lie on the left
        return lowestCommonAncestor(root->left,p,q);

        // This is the root where the two nodes splits    
        return root;  
    }
