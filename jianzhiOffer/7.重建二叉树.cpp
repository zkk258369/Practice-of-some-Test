#if 1
//用前序，中序重建二叉树

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution1  //rec
{
public:
	vector<int>::iterator findVin(vector<int> vin, int x)
	{
		vector<int>::iterator iter = vin.begin();
		for (; iter != vin.end(); iter++)
		{
			if (*iter == x)
			{
				break;
			}
		}
		return iter;
	}
	TreeNode* creat(vector<int> pre, vector<int> vin)
	{
		TreeNode* node = nullptr;
		if (!pre.empty())
		{
			vector<int>::iterator first = pre.begin();
			node = new TreeNode(*first);

			vector<int>::iterator pos = findVin(vin, *first);
			int m = pos - vin.begin();

			vector<int> newLeftPre(++first, first + m + 1);
			vector<int> newLeftVin(vin.begin(), --pos);
			node->left = creat(newLeftPre, newLeftVin);

			vector<int> newRightPre(first + 1 + m, pre.end());
			vector<int> newRightVin(++pos, vin.end());
			node->right = creat(newRightPre, newRightVin);
		}
		return node;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.empty() || vin.empty())
		{
			return nullptr;
		}
		TreeNode* bt = creat(pre, vin);
		if (bt == nullptr)
			return nullptr;
		return bt;
	}
};

class Solution2  // rec
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int inLen = inorder.size();
        if(0 == inLen || preorder.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        int pos = -1;
        for(int i=0; i<inLen; i++)
        {
            if(inorder[i] == preorder[0]) { pos = i; break; }
        }

        vector<int> newLeftPre(preorder.begin()+1, preorder.begin()+1+pos);
        vector<int> newRightPre(preorder.begin()+1+pos, preorder.end());
        vector<int> newLeftIn(inorder.begin(), inorder.begin()+pos);
        vector<int> newRightIn(inorder.begin()+pos+1,inorder.end());

        root->left = buildTree(newLeftPre, newLeftIn);
        root->right = buildTree(newRightPre, newRightIn);
        return root;
    }
};

class Solution3  // non rec
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
		if(preorder.size() == 0) return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);
		int preLen = preorder.size();
		stack<TreeNode*> sta;
		sta.push(root);
		int inorderIndex = 0;
		for(int i=1; i<preLen; i++)
		{
			int preVal = preorder[i];
			TreeNode* pnode = sta.top();
			if(pnode->val != inorder[inorderIndex])
			{
				pnode->left = new TreeNode(preVal);
				sta.push(pnode->left);
			}
			else
			{
				while(!sta.empty() && sta.top()->val == inorder[inorderIndex])
				{
					pnode = sta.top(); sta.pop();
					inorderIndex++;
				}
				pnode->right = new TreeNode(preVal);
				sta.push(pnode->right);
			}
		}
		return root;
    }
};

#endif