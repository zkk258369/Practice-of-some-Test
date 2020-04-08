#include<bits/stdc++.h>

using std::vector;
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

class Solution
{
public:
    vector<vector<int> > Print(TreeNode* root)
    {   
        vector<vector<int>> res;
        if(root == nullptr)
        {
            return res;
        }
        stack<TreeNode*> sta1, sta2;
        sta1.push(root);
        while(!sta1.empty() || !sta2.empty())
        {
            vector<int> vec1, vec2;
            TreeNode* p = nullptr; 
            while(!sta1.empty())
            {
                p = sta1.top();sta1.pop();
                vec1.push_back(p->val);
                if(p->left != nullptr)
                    sta2.push(p->left);
                if(p->right != nullptr)
                    sta2.push(p->right);          
            }
            if(!vec1.empty())
                res.push_back(vec1);
               
            while(!sta2.empty())
            {
                p = sta2.top();sta2.pop();
                vec2.push_back(p->val);
                if(p->right != nullptr)
                    sta1.push(p->right);
                if(p->left != nullptr)
                    sta1.push(p->left);
            }
            if(!vec2.empty())
                res.push_back(vec2);
        }
        return res;
    }
};