#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

/*
 * 问题1：
 * int SearchValue(const vector<int> &vec,const int val);
 * int SearchValue(vector<int> vec,const int val);
 * 这两个函数哪个函数设计的好，为什么？
 * 
 * 第一个设计的更好，加上const关键字可以防止原数组被改变，加上&可以节省空间
*/

/*
 * 问题2： 如果数据有重复，如何找到最left 端的数据？
*/
//处理重复值，且重复值非常多
#if 0
int FindValue(const vector<int>& vec, int val)
{
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (val < vec[mid]) right = mid - 1;
		else if (val > vec[mid]) left = mid + 1;
		else if (val == vec[mid]) right = mid - 1;
	}
	if (left < 0 || left > right || vec[left] != val) left = -1;
	return left;
}
#endif

/*
 * 问题3:   连续空间存储的数据有可能是升序，也有可能是降序，你如何解决？
 * 
*/

/*
 * 问题4:   如果是无序呢？
*/

/*
 * 问题5:   请编写快排。
*/

/*
 * 问题6： 寻找旋转排序数组中的最小值
*/

/*
 * 问题7： 查询重复的整型数。
*/

/*
 * 问题8： 制定新规则：
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n*n) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次，如何完成？
*/

/*
 * 问题9：
 * 查询第n小的整型数值。
 * 有二个数组ar,br, 大小都是n, 并且都是升序排序，在ar或br查找第n小的数值。
   例如 ar[]={1,3,5,7,9};  // n = 5
        br[]={2,4,6,8,10}; // n = 5
    output: 5
 * 规则如下：
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n)
 * 数组中有重复的数值。
*/

/*
 * 问题10：
 * 给一个有序数组，将这些数字插入到二叉树中，使得这棵树是一个avl树
*/
#if 0
typedef struct BtNode
{
	int val;
	BtNode* leftchild;
	BtNode* rightchild;
	static BtNode* BuyNode()
	{
		BtNode* newNode = new BtNode();
		memset(newNode, 0, sizeof(BtNode));
		return newNode;
	}
};

BtNode* Create(const int* arr, int left, int right)
{
	BtNode* newNode = nullptr;
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		newNode = BtNode::BuyNode();
		newNode->val = arr[mid];
		newNode->leftchild = Create(arr, left, mid - 1);
		newNode->rightchild = Create(arr, mid + 1, right);
	}
	return newNode;
}

BtNode* CreateTree(const int* arr, int n)
{
	if (nullptr == arr || n < 1) return nullptr;
	else return Create(arr, 0, n - 1);
}


int FindValue(const vector<int>& vec, int val)
{
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (val < vec[mid]) right = mid - 1;
		else if (val > vec[mid]) left = mid + 1;
		else
		{
			return mid;
		}
	}
	return -1;
}
#endif

/*
 * 问题11：有一组数对，pair(a, b)，将其插入到一个二叉树中，使得中序遍历a是升序，而b是按照最大树的方式来建立。
*/
#if 0
typedef struct BtNode
{
	pair<int, int> val;
	BtNode* leftchild;
	BtNode* rightchild;
	static BtNode* BuyNode()
	{
		BtNode* newNode = new BtNode();
		memset(newNode, 0, sizeof(BtNode));
		return newNode;
	}
};

int FindMax(vector<pair<int, int>>& vec)
{
	int index = 0;
	pair<int, int> max = vec[index];
	for (int i = 1; i<vec.size(); i++)
	{
		if (vec[i].second > max.second)
		{
			max = vec[i];
			index = i;
		}
	}
	return index;
}

int partition(vector<pair<int, int>>& vec)
{
	pair<int, int> pivot = vec[0];
	int left = 0;
	int right = vec.size();
	while (left <= right)
	{
		while (left <= right)
		{
			if (vec[right].first < pivot.first) vec[left] = vec[right];
			right--;
		}
		while (left <= right)
		{
			if (vec[left].first > pivot.first) vec[right] = vec[left];
			left++;
		}
	}
	vec[left] = pivot;
	return left;
}

BtNode* CreateTree(vector<pair<int, int>>& vec)
{
	int maxIndex = FindMax(vec);
	swap(vec[maxIndex], vec[0]);
	int pos = partition(vec);
	vector<pair<int, int>> left(vec.begin(), vec.begin() + pos);
	vector<pair<int, int>> right(vec.begin() + pos + 2, vec.end());
	BtNode* root = BtNode::BuyNode();
	root->val = vec[pos];
	root->leftchild = CreateTree(left);
	root->rightchild = CreateTree(right);
	return root;
}
#endif

/*
 * 问题12：有序二维数组的二分查找
*/

int main()
{
	return 0;
}