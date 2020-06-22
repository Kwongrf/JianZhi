#include<iostream>
#include<vector>
#include<stack>
#include<queue>
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
            vector<vector<int> > result;
            queue<TreeNode*> Q;
            if(!pRoot)
                return result;
            
            Q.push(pRoot);
            while(!Q.empty())
            {
                vector<int> layer;
                int size = Q.size();
                while(size--)
                {
                    TreeNode* node = Q.front();
                    layer.push_back(node->val);
                    if(node->left)
                        Q.push(node->left);
                    if(node->right)
                        Q.push(node->right);
                    Q.pop();
                }
                result.push_back(layer);
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

