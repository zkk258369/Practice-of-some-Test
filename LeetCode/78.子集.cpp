#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
using namespace std;

/*
 *  给所有子集按照哈夫曼树编码，通过递归访问，
 * 添加所有子集
*/
class Solution1
{
public:
	void sub(vector<vector<int>>& res, vector<int>& nums, vector<int> brr, int i)
	{
		vector<int> tmp;
		if (i >= nums.size())
		{
			for (int i = 0; i<nums.size(); i++)
			{
				if (brr[i]) tmp.push_back(nums[i]);
			}
			res.push_back(tmp);
		}
		else
		{
			brr[i] = 1;
			sub(res, nums, brr, i + 1);
			brr[i] = 0;
			sub(res, nums, brr, i + 1);
		}
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> brr(nums.size(), 0);
		sub(res, nums, brr, 0);
		return res;
	}
};

/*
 *  首先给res添加空集，然后给res中每个子集添加nums中的数字，
 * 生成新的子集后添加到res，重复这个过程，直到添加完所有nums中的数字
*/
class Solution2
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		res.push_back(vector<int>()); // 加空集
		for (int num : nums)
		{
			vector<vector<int>> newSubsets;
			for (vector<int> cur : res) // 给res中每个子集添加新元素，生成新子集
			{
				vector<int> tmp = cur;
				tmp.push_back(num);
				newSubsets.push_back(tmp);
			}
			for (vector<int> cur : newSubsets) // 将新子集添加到res中
			{
				res.push_back(cur);
			}
		}
		return res;
	}
};

/*
 *  当子集大小为k时，用函数backtrack求出大小为k的所有子集并添加res中，
 * backtrack()过程用回溯法求解
*/
class Solution3
{
public:
	void backtrack(int first, vector<int>& cur, vector<int>& nums)
	{
		if (cur.size() == k)
		{
			res.push_back(cur);
		}
		for (int i = first; i < n; ++i)
		{
			cur.push_back(nums[i]);
			backtrack(i + 1, cur, nums);
			cur.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		n = nums.size();
		// 当子集大小为k时，用函数backtrack求出大小为k的所有子集并添加res中
		for (k = 0; k < n + 1; k++) 
		{
            vector<int> cur;
			backtrack(0, cur, nums);
		}
		return res;
	}
private:
	vector<vector<int>> res;
	int n; // nums.size()
	int k;
};

/*
 *  将nums中的元素与二进制位映射起来，1代表添加这个数字到单个子集中，
 * 0代表不添加。生成所有可能二进制位，并将每种映射添加到res中
*/
class Solution4
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		int n = nums.size();
		for (int i = (int)pow(2, n); i < (int)pow(2, n + 1); i++)
		{
			string bit = bitset<32>(i).to_string();
			bit.erase(0, 32 - n - 1);
			vector<int> cur;
			for (int j = 1; j <= n; j++)
			{
				if (bit[j] == '1') cur.push_back(nums[j-1]);
			}
			res.push_back(cur);
		}
		return res;
	}
};