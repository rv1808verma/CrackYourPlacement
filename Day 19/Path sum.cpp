// https://leetcode.com/problems/path-sum/description/

    bool isLeaf(TreeNode*a ){
        return !(a->left || a->right);
    }

    bool PathSum(TreeNode* a, int t,int pathSum){

        if(!a) return 0;

        // Add To pathSum 
        pathSum+=a->val;

        // Either of 3 Possibility of Finding :
        if(isLeaf(a) && t==pathSum || PathSum(a->left,t,pathSum) || PathSum(a->right,t,pathSum)) return true;

        // If Not Found  return false
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return PathSum(root,targetSum,0);   
    }
