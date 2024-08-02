// https://leetcode.com/problems/invert-binary-tree/

    void swapNode(TreeNode* root){
        if(root==NULL) return;
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        swapNode(root->left);
        swapNode(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swapNode(root);
        return root;
    }  
