#include<bits/stdc++.h>

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
    {}
};

class Solution
{
public:
    bool isSymmetrical(TreeNode* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        return Compare(root->left, root->right);
    }
private:
    bool Compare(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr)
        {
            return right==nullptr;
        }
        if(right == nullptr)
        {
            return false;
        }
        if(left->val != right->val)
        {
            return false;
        }
        return Compare(left->left, right->right) && Compare(right->left, left->right);
    }
};