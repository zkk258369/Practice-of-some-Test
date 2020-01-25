#if 1
#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<iterator>
#include<queue>


using std::queue;
using std::iterator;
using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

}TreeNode;

//非递归方式 求二叉树的深度

//递归方式
/*
如果一棵树只有一个结点，那么它的深度为1；
如果根结点只有左子树没有右子树，那么树的深度是左子树的深度加1，加1是加上根节点这一层
如果既有左子树又有右子树，那么树的深度应该是左、右子树中深度较大的值再加1
*/

class SolutionNoRecersive
{
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left > right ? left : right) + 1;
	}
};

//非递归  与层次遍历类似
class Solution
{
public:
	int TreeDepth(TreeNode* pRoot)
	{
		int deepth = 0;
		queue<TreeNode*> que;
		if (pRoot == nullptr)
			return deepth;
		que.push(pRoot);
		que.push(nullptr);

		while (!que.empty())
		{
			TreeNode* p = que.front(); que.pop();
			if (p == nullptr)
			{
				deepth++;
				continue;
			}
			if (p->left != nullptr)
			{
				que.push(p->left);
			}
			if (p->right != nullptr)
			{
				que.push(p->right);
			}
			TreeNode* pnext = que.front();
			if (pnext == nullptr && que.size() != 1)
			{
				que.push(nullptr);
			}
		}
		return deepth;
	}
};


#endif