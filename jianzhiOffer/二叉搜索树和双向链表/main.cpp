#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) 
        :val(x), left(NULL), right(NULL) 
    {}
};

class Solution
{
public:
    TreeNode* Convert(TreeNode* pRoot)//转换成升序链表
    {
        if(pRoot == nullptr)
            return nullptr;

        TreeNode* pnewRoot = nullptr;
        TreeNode* p = pRoot;
        TreeNode* pre = p;
        stack<TreeNode*> sta;
        bool isFirst = true;

        while(!sta.empty() || p != nullptr)
        {
            while(p != nullptr)
            {
                sta.push(p);
                p = p->left;
            }
            p = sta.top();sta.pop();
            if(isFirst)
            {
                pnewRoot = p;
                pre = p;
                isFirst = false;
            }
            else
            {
                pre->right = p;
                p->left = pre;
                pre = p;
            }
            p = p->right;
        }
        return pnewRoot;
    }
};

class Solution2
{
public:
    void convertNode(TreeNode* pNode, TreeNode** lastNodeOfList)
    {
        if(pNode == nullptr)
            return;
        if(pNode->left != nullptr)
            convertNode(pNode->left, lastNodeOfList);
        
        if(*lastNodeOfList != nullptr)
        {
            (*lastNodeOfList)->right = pNode;
        }
        pNode->left = *lastNodeOfList;
        *lastNodeOfList = pNode;
        
        if(pNode->right != nullptr)
            convertNode(pNode->right, lastNodeOfList);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* lastNodeOfList = nullptr;
        convertNode(pRootOfTree, &lastNodeOfList);
        
        TreeNode* p = lastNodeOfList;
        while(p != nullptr && p->left != nullptr)
        {
            p = p->left;
        }
        return p;
    }
};