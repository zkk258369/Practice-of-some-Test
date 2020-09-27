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