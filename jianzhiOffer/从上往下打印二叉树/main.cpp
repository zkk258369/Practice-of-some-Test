#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x){}
}TreeNode;
class Solution
{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        std::vector<int> vec;
        if(root == nullptr)
            return vec;
        
        std::queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            struct TreeNode* ptmp = que.front();
            que.pop();
            if(ptmp->left != nullptr)
                que.push(ptmp->left);
            if(ptmp->right != nullptr)
                que.push(ptmp->right);
            vec.push_back(ptmp->val);
        }
        return vec;
    }
};