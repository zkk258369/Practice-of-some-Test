#include <bits/stdc++.h>

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value)
        :val(value)
    {}
}TreeNode;
class Solution
{
public:
    bool _isValidBST(TreeNode* root, long long min, long long max)
    {
        if(nullptr == root) return true;
        if(root->val >= max || root->val <= min) return false;
        return _isValidBST(root->left, min, root->val) & _isValidBST(root->right, root->val, max); 
    }
    bool isValidBST(TreeNode* root)
    {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }
};