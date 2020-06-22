/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>result;
        if(!root)
            return result;
        queue<TreeNode*>Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            TreeNode* node = Q.front();
            result.push_back(node->val);
            Q.pop();
            if(node->left)
                Q.push(node->left);
            if(node->right)
                Q.push(node->right);
        }
        return result;
    }
};
