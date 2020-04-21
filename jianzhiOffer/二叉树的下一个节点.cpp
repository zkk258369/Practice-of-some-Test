#include<bits/stdc++.h>

typedef struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) 
        :val(x), left(NULL), right(NULL), next(NULL)
    {}
}TreeLinkNode;

class Solution
{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        if(pNode->right != NULL)
        {
            pNode = pNode->right;
            while(pNode->left != NULL)
                pNode = pNode->left;
            return pNode;
        }
        while(pNode->next != NULL)
        {
            TreeLinkNode* pa = pNode->next;
            if(pa->left == pNode)
                return pa;
            pNode = pNode->next;
        }
        return NULL;
    }
};