#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        vector<vector<int> >result;
        if(!pRoot) return result;
        
        stack1.push(pRoot);
        while(!stack1.empty() || !stack2.empty())
        {
            vector<int>left2right;
            while(!stack1.empty())
            {
                TreeNode* node = stack1.top();
                left2right.push_back(node->val);
                if(node->left)
                	stack2.push(node->left);
                if(node->right)
					stack2.push(node->right);
                stack1.pop();
            }
            if(left2right.size() > 0)
                result.push_back(left2right);
            
            vector<int>right2left;
            while(!stack2.empty())
            {
                TreeNode* node = stack2.top();
                right2left.push_back(node->val);
                if(node->right)
                	stack1.push(node->right);
                if(node->left)
               		stack1.push(node->left);
                stack2.pop();
            }
            if(right2left.size() > 0)
                result.push_back(right2left);
        }
        return result;
    }
    
};

int main()
{
	TreeNode* pRoot1 = new TreeNode(1);
	pRoot1->left = new TreeNode(2);
	pRoot1->right = new TreeNode(3);
	TreeNode* curNode = pRoot1->left;
	curNode->left = new TreeNode(4);
	

	Solution s;
    vector<vector<int> >  re = s.Print(pRoot1);
    
}

