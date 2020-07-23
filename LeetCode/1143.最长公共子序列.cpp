#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int len1 = text1.size();
		int len2 = text2.size();
		vector<int> dp(len2 + 1);
		for (int i = len1 - 1; i >= 0; i--)
		{
			int nextRowRight = dp[len2];
			for (int j = len2 - 1; j >= 0; j--)
			{
				int tmp = dp[j];
				if (text1[i] == text2[j])
				{
					dp[j] = 1 + nextRowRight;
				}
				else
				{
					dp[j] = max(dp[j], dp[j + 1]);
				}
				nextRowRight = tmp;
			}
		}
        return dp[0];
	}
};