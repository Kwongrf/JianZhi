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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int>way;
        if(!root)
            return all_ways;
        search(root, expectNumber, way);
        return all_ways; 
    }
    void search(TreeNode* root, int leftNumber, vector<int>way)
    {
        if(!root)
            return;
	    if(root->val == leftNumber && !root->left && !root->right)
	    {
	    	way.push_back(root->val);
	    	all_ways.push_back(way);
		}    
	    else
	    {
	    	way.push_back(root->val);
	        search(root->left, leftNumber - root->val, way);
	        search(root->right, leftNumber - root->val, way);
		}
        
    }
private:
    vector<vector<int> >all_ways;
};
void show(vector<int>v)
{
	for(int i = 0; i < v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
int main()
{
	TreeNode* pRoot1 = new TreeNode(1);
	pRoot1->left = new TreeNode(2);
	pRoot1->right = new TreeNode(3);
	TreeNode* curNode = pRoot1->left;
	curNode->left = new TreeNode(4);
	

	Solution s;
    vector<vector<int> >  re = s.FindPath(pRoot1,7);
    show(re[0]);
}
