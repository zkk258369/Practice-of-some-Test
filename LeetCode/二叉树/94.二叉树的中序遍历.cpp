#include<bits/stdc++.h>

using std::vector;
using std::stack;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr)
    {}
}TreeNode;

class Solution  //non recursive
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(nullptr == root)
            return res;       
        TreeNode* ptr = root;
        stack<TreeNode*> sta;
        while(!sta.empty() || nullptr != ptr)
        {
            while(nullptr != ptr)
            {
                    sta.push(ptr);
                    ptr = ptr->left;
            }
            ptr = sta.top();sta.pop();
            res.push_back(ptr->val);
            ptr = ptr->right; 
        }
        return res;
    }
};