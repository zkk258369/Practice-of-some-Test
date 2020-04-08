#include<bits/stdc++.h>

using std::vector;
using std::queue;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x){}
}TreeNode;

/*
 * 从上到下按层打印二叉树，同一层结点从左至右输出。
 * 每一层输出一行。
*/
class Solution
{
public:
    vector<vector<int>> Print(TreeNode* root)
    {
        vector<vector<int>> res;
        if(root != nullptr)
        {       
            queue<TreeNode*> que;
            que.push(root);       
            while(!que.empty())
            {
                vector<int> vec;
                int i = que.size();
                while(i--)
                {
                    TreeNode* p = que.front();que.pop();
                    vec.push_back(p->val);
                    if(p->left != nullptr)
                        que.push(p->left);
                    if(p->right != nullptr)
                        que.push(p->right);  
                }
                if(!vec.empty())
                    res.push_back(vec);
            }           
        }
        return res;
    }
};