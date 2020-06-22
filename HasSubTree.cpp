#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if(!pRoot2)
    		return false;
        if(!pRoot1&&pRoot2)
            return false;//子树不为空，主数为空，肯定不是子结构了
        if(pRoot1->val == pRoot2->val)
            if(isSubTree(pRoot1, pRoot2))
                return true; 
        return HasSubtree(pRoot1->left, pRoot2)||HasSubtree(pRoot1->right, pRoot2);
    }
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)
            return true;
        if(!pRoot1&&pRoot2)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        if(pRoot1->val==pRoot2->val)
            return isSubTree(pRoot1->left, pRoot2->left)&&isSubTree(pRoot1->right, pRoot2->right);
    }
};
int main()
{
	TreeNode* pRoot1 = new TreeNode(1);
	pRoot1->left = new TreeNode(2);
	pRoot1->right = new TreeNode(3);
	TreeNode* curNode = pRoot1->left;
	curNode->left = new TreeNode(4);
	
	TreeNode* pRoot2 = new TreeNode(1);
//	pRoot2->left = new TreeNode(2);
//	curNode = pRoot2->left;
//	curNode->left = new TreeNode(5);
	Solution s;
	cout<<s.HasSubtree(pRoot1, pRoot2);
}
