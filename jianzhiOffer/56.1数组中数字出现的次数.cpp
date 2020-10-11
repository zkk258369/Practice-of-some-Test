#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	vector<int> singleNumbers(vector<int>& nums)
	{
		int x = 0;
		for (int i : nums) x ^= i;
		for (int i = 0; i<32; i++)
		{
			if (x & 1 == 1)
			{
				x = 1;
				x <<= i;
				break;
			}
			else x >>= 1;
		}
		vector<int> v1;
		vector<int> v2;
		for (int i : nums)
		{
			if ((i & x) == x) v1.push_back(i);
			else v2.push_back(i);
		}
		vector<int> res(2, 0);
		for (int i : v1) res[0] ^= i;
		for (int i : v2) res[1] ^= i;
		return res;
	}
};


//只出现一次的数字，其余数字出现两次，数字都有序
// 用二分法做，根据这个数字两侧的数字下标的奇偶不同。
int fun(vector<int>& vec)
{
	int left = 0;
	int right = vec.size() - 1;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (vec[mid] == vec[mid - 1])
		{
			if (mid % 2 == 0) right = mid - 2;
			else left = mid + 1;
		}
		else if (vec[mid] == vec[mid + 1])
		{
			if (mid % 2 == 0) left = mid + 2;
			else right = mid - 1;
		}
		else return vec[mid];
	}
	return vec[left];
}

int main()
{
	vector<int> vec = { 1, 1, 2, 2, 3, 4, 4, 5 };
	int res = fun(vec);
	cout << res << endl;
	return 0;
}