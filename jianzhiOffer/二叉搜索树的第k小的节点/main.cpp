#include<bits/stdc++.h>

using std::stack;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        :val(x)
    {}
}TreeNode;

/*
 * 我的思路：在中序遍历，按照从小到大填充vector，当vector.size()等于k时返回答案。
*/

class Solution  //recursive
{
public:
    Solution(int x = 0) :count(x){}
    TreeNode* InOrder(TreeNode* root, int k)
    {
        if(nullptr != root)
        {
            TreeNode* L = InOrder(root->left, k);
            if(nullptr != L)
            {
                return L;
            }
            ++count;
            if(k == count)
            {
                return root;
            }
            TreeNode* R = InOrder(root->right, k);
            if(nullptr != R)
            {
                return R;
            } 
        }
        return nullptr;
    }
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(nullptr == root || 0 == k)
        {
            return nullptr;
        }
        //如果k大于节点数返回nullptr
        return InOrder(root, k);
    }
private:
    int count;
};

class Solution  //non recursive
{
public:
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(nullptr == root || 0 == k)
        {
            return nullptr;
        }
        //如果k大于节点数返回nullptr
        
        stack<TreeNode*> sta;
        int count = 0;
        TreeNode* p = root;
        while(!sta.empty() || nullptr != p)
        {
            if(nullptr != p)
            {
                sta.push(p);
                p = p->left;
            }
            else
            {
                p = sta.top();sta.pop();
                ++count;
                if(count == k)
                    return p;
                p = p->right;
            }
        }
        return nullptr;
    }
};