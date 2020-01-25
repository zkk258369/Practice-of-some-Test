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

//�ǵݹ鷽ʽ ������������

//�ݹ鷽ʽ
/*
���һ����ֻ��һ����㣬��ô�������Ϊ1��
��������ֻ��������û������������ô�������������������ȼ�1����1�Ǽ��ϸ��ڵ���һ��
���������������������������ô�������Ӧ����������������Ƚϴ��ֵ�ټ�1
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

//�ǵݹ�  ���α�������
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