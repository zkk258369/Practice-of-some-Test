/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法
（先后次序不同算不同的结果）。
*/

#include<bits/stdc++.h>

class Solution1
{
public:
	Solution1()
	{
		for (int i = 0; i<=100; i++) arr[i] = 0;
		arr[0] = 1;
		arr[1] = 1;
        arr[2] = 2;
	}
	int numWays(int n)
	{
		int res = 0;
        if(arr[n] != 0) res = arr[n];
		else
		{
			int a = numWays(n - 1);
			int b = numWays(n - 2);
			arr[n] = (a + b) % 1000000007;
			res = arr[n];
		}
		return res;
	}
private:
	int arr[101];
};

class Solution
{
public:
    int numWays(int n)
    {
        int a = 1;
        int b = 1;
        int sum = 1;
        for(int i=2; i<=n; i++)
        {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return sum;
    }
};