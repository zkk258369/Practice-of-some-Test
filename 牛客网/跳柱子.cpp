#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int>& h, int n, vector<int>& dp, int k, int s)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - k;
		if (j < 0) j = 0;
		// 不使用超能力到达j，不使用超能力从j到达i
		for (; j < i; j++)
		{
			if (dp[j] == 1 && h[j] >= h[i])
			{
				dp[i] = 1; break;
			}
		}
		if (dp[i] == 1) continue;
		j = i - k; if (j < 0) j = 0;
		for (; j < i; j++)
		{
			// 不使用超能力到达 j, 再使用超能力从 j 到达 i
			if (s > 0 && dp[j] == 1 && h[j] < h[i])
			{
				dp[i] = 2; break;
			}
			// 使用超能力到达 j，不使用超能力从 j 到达 i
			else if (dp[j] == 2 && h[j] >= h[i])
			{
				dp[i] = 2; break;
			}
		}
		// 上诉两种情况都不满足则说明不能到达 i
		if (dp[i] == -1) dp[i] = 0;
	}
	return (dp[n - 1] == 1 || dp[n - 1] == 2);
}

int main() {
	int T, n, k;
	scanf("%d", &T);
	vector<int> h;
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &n, &k);
		vector<int> dp(n, -1);
		h.clear();
		for (int j = 0; j < n; j++)
		{
			int num;
			scanf("%d", &num);
			h.push_back(num);
		}
		dp[0] = 1;
		bool res = helper(h, n, dp, k, 1);
		if (res) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}