#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.size();
		if (len < 2) return s;
		int maxlen = 1;
		int begin = 0;
		
		vector<vector<int>> dp(len, vector<int>(len));
		for (int i = 0; i < len; i++)
		{
			dp[i][i] = true;
		}
		for (int j = 1; j < len; j++)
		{
			for (int i = 0; i < j; i++)
			{
				if (s[i] != s[j]) dp[i][j] = false;
				else
				{
					if (j - i < 3) dp[i][j] = true;
					else dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && j - i + 1 > maxlen)
				{
					maxlen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxlen);
	}
};
