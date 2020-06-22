/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode || (!pNode->next&&!pNode->right))
            return NULL;
        if(pNode->right)
        {
            return GetLeftest(pNode->right);
        }
        if(!pNode->right)//没有右节点
        {
            return GetFatherAsLeft(pNode);
        }
    }
    TreeLinkNode* GetLeftest(TreeLinkNode* pNode)
    {
        if(!pNode->left) return pNode;
        
        return GetLeftest(pNode->left);
    }
    TreeLinkNode* GetFatherAsLeft(TreeLinkNode* pNode)
    {
        if(!pNode->next)
            return NULL;
        if(pNode->next->left == pNode)
            return pNode->next;
        return GetFatherAsLeft(pNode->next);
    }
};
