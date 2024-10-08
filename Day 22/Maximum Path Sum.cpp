// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

int findMaxPathSum(TreeNode* root, int & maxi) {
    if (root == NULL) return 0;
    int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
    int val = root -> val;
    maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;
}
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
