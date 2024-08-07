// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

    void inorder(TreeNode* node, vector<int>&arr){
        if(!node) return;
        inorder(node->left,arr);
        arr.push_back(node->val);
        inorder(node->right,arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        int ksmallest=arr[k-1];
        return ksmallest;
    }
