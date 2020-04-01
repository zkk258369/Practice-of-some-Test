#include<iostream>


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {}
};
 
class Solution  //recursive
{
public:
    Solution(TreeNode* answer=nullptr)
        :ans(answer)
        {}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        recursiveTree(root, p, q);
        return ans;
    }
private:
    bool recursiveTree(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
            return false;
        
        int left = recursiveTree(root->left, p, q) ? 1 : 0;
        int right = recursiveTree(root->right, p, q);
        int mid = (root == p || root == q) ? 1 : 0;

        if(mid + left + right >= 2)
            ans = root;
        
        return(mid + left + right > 0);
    }
private:
    TreeNode* ans;
};

class Solution  //recursive2
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr) return right;
        if(right == nullptr) return left;

        return root;
    }

};