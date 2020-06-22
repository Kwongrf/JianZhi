#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void show(vector<int>v)
{
	for(int i = 0; i < v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() && vin.empty())
        	return NULL;
		if(pre.size() == 1 && vin.size() == 1)
            return new TreeNode(pre[0]);
        
        int pivot = pre[0];
        int i = 0; //find(vin.begin(),vin.end(),pivot)
        for(; i < vin.size(); i++)
        {
            if(pivot == vin[i])
                break;
        }
        if(i > vin.size())
            return NULL;
        vector<int> left_vin(vin.begin(), vin.begin()+i);
        show(left_vin);
        vector<int> right_vin(vin.begin()+i+1, vin.end());
        show(right_vin);
        vector<int> left_pre(pre.begin()+1,pre.begin()+i+1);
        show(left_pre);
        vector<int> right_pre(pre.begin()+i+1, pre.end());
        show(right_pre);
        
        TreeNode* root = new TreeNode(pre[0]);
        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);
        return root;
        
    }
};
void pre_list(TreeNode* root)
{
	if(!root) return;
	cout<<root->val<<" ";
	pre_list(root->left);
	pre_list(root->right);
	
}
int main()
{
	Solution s;
	int a[8] = {1,2,4,7,3,5,6,8};
	int b[8] = {4,7,2,1,5,3,8,6};
	vector<int>pre(a, a+8);
	vector<int>vin(b, b+8);
	TreeNode* root = s.reConstructBinaryTree(pre, vin);
	pre_list(root);
}
