#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> dp(amount + 1);
		int len = coins.size();
		for (int i = 1; i <= amount; i++)
		{
			int minCount = INT_MAX;
			for (int j = 0; j<len; j++)
			{
				int tmp = i - coins[j];
				if (tmp >= 0 && dp[tmp] >= 0) minCount = min(dp[tmp], minCount);
			}
			if (minCount == INT_MAX) dp[i] = -1;
			else dp[i] = minCount + 1;
		}
		if (dp[amount] != -1) return dp[amount];
		else return -1;
	}
};

int main()
{
	vector<int> vec = { 2, 5, 10, 1 };
	int amount = 27;
	Solution s;
	int res = s.coinChange(vec, amount); //4
	cout << res << endl;
	return 0;
}