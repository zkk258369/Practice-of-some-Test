#if 1
#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<iterator>
#include<vector>

using std::vector;
using std::iterator;
using namespace std;


struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		:val(x), left(NULL), right(NULL)
	{}
};

//����A��B ���������ж�B�Ƿ�ΪA�������������������������ӽṹ
class Solution {
public:
	bool doesTree1haveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;

		return doesTree1haveTree2(pRoot1->left, pRoot2->left) && doesTree1haveTree2(pRoot1->right, pRoot2->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		if (pRoot1 != nullptr && pRoot2 != nullptr)
		{
			if (pRoot1->val == pRoot2->val)
			{
				res = doesTree1haveTree2(pRoot1, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return res;
	}
};

#endif