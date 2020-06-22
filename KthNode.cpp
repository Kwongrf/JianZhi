/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot)
            return NULL;
        TreeNode* kNode = pRoot;
        int rank = 0;
        if(findKth(pRoot, kNode, rank, k))
            return kNode;
        return NULL;
        
    }
    bool findKth(TreeNode* pRoot,TreeNode* &kNode, int& rank, int k)
    {
        
        if(pRoot->left)
        {
            if(findKth(pRoot->left, kNode, rank, k))
                return true;
        }    
            
        rank++;
        if(rank == k)
        {
            kNode = pRoot;
            return true;
        }
        if(pRoot->right)
        {
            if(findKth(pRoot->right, kNode, rank, k))
                return true;
        }
        return false;
        
    }

    
};
