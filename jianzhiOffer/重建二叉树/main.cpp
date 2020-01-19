#if 1

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<iterator>
#include<vector>

using std::vector;
using std::iterator;
using namespace std;


//用前序，中序重建二叉树
typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

}TreeNode;

class Solution
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

class Solution2
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		int inlen = vin.size();
		if (inlen == 0)
			return nullptr;

		TreeNode* root = new TreeNode(pre[0]);

		int pos = 0;
		for (int i = 0; i < inlen; i++)
		{
			if (vin[i] == pre[0])
			{
				pos = i;
				break;
			}
		}

		vector<int> newLeftPre(++pre.begin(), pre.begin() + pos + 1);
		vector<int> newLeftVin(vin.begin(), vin.begin() + pos);

		vector<int> newRightPre(pre.begin() + 1 + pos, pre.end());
		vector<int> newRightVin(vin.begin() + pos + 1, vin.end());

		root->left = reConstructBinaryTree(newLeftPre, newLeftVin);
		root->right = reConstructBinaryTree(newRightPre, newRightVin);
		return root;
	}
};

int main()
{
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> vec(arr, arr + 8);
	for (int i = 0; i < 7; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	vector<int>::iterator first = vec.begin();
	vector<int> newVec(++first, first + 3 + 1);//first++会出错
	for (int i = 0; i < newVec.size(); i++)
	{
		cout << newVec[i] << " ";
	}
	system("pause");
	return 0;
}

#endif