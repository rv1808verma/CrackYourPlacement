// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

    TreeNode* createTree(vector<int>& nums, int start, int end){
        int mid=start+(end-start)/2;
        if(start>end) return NULL;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=createTree(nums,start,mid-1);
        node->right=createTree(nums,mid+1,end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return createTree(nums,0,nums.size()-1);
    }
