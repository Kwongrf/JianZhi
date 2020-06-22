#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

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
    char* Serialize(TreeNode *root) {  
        if(!root)
            return "#";
        string val_str = to_string(root->val);
        val_str += '!';
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* str = new char[val_str.length()+strlen(left)+strlen(right)];
        strcpy(str, val_str.c_str());
        strcat(str, left);
        strcat(str, right);
        return str;
    }
    TreeNode* deserialize(char *&s)
    {
        if(*s == '#')
        {
            s++;
            return NULL;
        }
        int num = 0;
        while(*s != '!')
        {
            num = num * 10 + (*s - '0');
            s++; 
        }
        s++;
        TreeNode* root = new TreeNode(num);
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
    TreeNode* Deserialize(char *str) {
       return deserialize(str);
    }
/* 
链接：https://www.nowcoder.com/questionTerminal/cf7e25aa97c04cc1a68c8f040e71fb84?f=discussion
来源：牛客网
*/
typedef TreeNode node;
typedef TreeNode* pnode;
typedef int* pint;
class Solution {
    vector<int> buf;
    void dfs(pnode p){
        if(!p) buf.push_back(0x23333);
        else{
            buf.push_back(p -> val);
            dfs(p -> left);
            dfs(p -> right);
        }
    }
    pnode dfs2(pint& p){
        if(*p == 0x23333){
            ++p;
            return NULL;
        }
        pnode res = new node(*p);
        ++p;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }
public:
    char* Serialize(TreeNode *p) {
        buf.clear();
        dfs(p);
        int *res = new int[buf.size()];
        for(unsigned int i = 0; i < buf.size(); ++i) res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return dfs2(p);
    }
};

};
