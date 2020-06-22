class Solution {
public:
    bool flag = true;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = TreeDepth(pRoot);
        return flag;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        int leftDepth = TreeDepth(pRoot->left) + 1;
        int rightDepth = TreeDepth(pRoot->right) + 1;
        if(abs(leftDepth - rightDepth) > 1)
            flag = false;
        return max(leftDepth, rightDepth);
    }
};
