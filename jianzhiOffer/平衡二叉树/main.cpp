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

class Solution1 //从上往下遍历
{
public:
    int DepthOfBinaryTree(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        else
        {
            int L = DepthOfBinaryTree(root->left);
            int R = DepthOfBinaryTree(root->right);
            return L > R ? L+1 : R+1;
        }
    }
    bool IsBalanced_Solution(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        int DL = DepthOfBinaryTree(root->left);
        int DR = DepthOfBinaryTree(root->right);
        int diff = abs(DL-DR);
        if(IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right) && (diff<=1))
            return true;
        else
            return false;
    }
};

class Solution2 //从下往上遍历
{
public:
    int DepthOfBinaryTree(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int DL = DepthOfBinaryTree(root->left);
        if(DL == -1) return -1;
        int DR = DepthOfBinaryTree(root->right);
        if(DR == -1) return -1;
        
        return abs(DL-DR)>1 ? -1 : DL>DR ? DL+1 : DR+1;
    }
    bool IsBalanced_Solution(TreeNode* root)
    {
        return DepthOfBinaryTree(root) != -1;
    }
};

int main()
{
    return 0;
}