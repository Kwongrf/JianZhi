#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<stdlib.h>
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
    TreeNode* convert(TreeNode* pRootOfTree, bool left)
    {
        if(!pRootOfTree) return NULL;
        if(!pRootOfTree->left&&!pRootOfTree->right)
            return pRootOfTree; 
        if(pRootOfTree->left)
        {
            pRootOfTree->left = convert(pRootOfTree->left, 1);
            pRootOfTree->left->right = pRootOfTree;
        }
        if(pRootOfTree->right)
        {
            pRootOfTree->right = convert(pRootOfTree->right, 0);
            pRootOfTree->right->left = pRootOfTree;
        } 
        if(left && pRootOfTree->right)
            return pRootOfTree->right;
        else if(!left && pRootOfTree->left)
        	return pRootOfTree->left;
        else
            return pRootOfTree;
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
    	if(!pRootOfTree)
            return NULL;
        TreeNode* result = convert(pRootOfTree, 1);
        while(result->left) result = result->left;
        return result;
    }
};

int main()
{
	Solution s;
	TreeNode* pRoot1 = new TreeNode(10);
	pRoot1->left = new TreeNode(6);
	pRoot1->right = new TreeNode(14);
	
	TreeNode* curNode = pRoot1->left;
	curNode->left = new TreeNode(4);
	curNode->right = new TreeNode(8);
	
	curNode = pRoot1->right;
	curNode->left = new TreeNode(12);
	curNode->right = new TreeNode(16);
	
	TreeNode* a = s.Convert(pRoot1);
	
	
	while(a->right)
	{
		cout<<a->val<<" ";
		a = a->right;
	}
	cout<<a->val<<endl;
	while(a->left)
	{
		cout<<a->val<<" ";
		a = a->left;
	}
	cout<<a->val<<endl;
}
