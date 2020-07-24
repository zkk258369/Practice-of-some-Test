#include<iostream>
#include<vector>
using namespace std;

class Solution //动态规划
{
public:
	int cuttingRope(int n)
	{
		if (n < 2) return 0;
		if (n == 2) return 1;
		if (n == 3) return 2;
		vector<int> vec(n + 1, 0);
		vec[0] = 0;
		vec[1] = 1;
		vec[2] = 2;
		vec[3] = 3;
		int max = 0;
		for (int i = 4; i <= n; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				int tmp = vec[j] * vec[i - j];
				if (tmp > max) max = tmp;
				vec[i] = max;
			}
		}
		return vec[n];
	}
};