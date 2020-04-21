/*
大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
1.递归虽然容易写，但又效率问题
2.先算出f(0),f(1),f(2)…依次往下计算，直到算出我们所需要的f(n),时间复杂度为O(n)
3.时间复杂度为O(logn)的解法，一般不实用，但可以用来炫技
*/
#if 0
#include<iostream>

class Solution
{
public:
	int Fibonacci(int n)
	{
		//if (n == 0)
		//{
		//	return 0;
		//}
		//if (n == 1)
		//{
		//	return 1;
		//}

		//int a = 0;
		//int b = 1;
		//int m;
		//for (int i = 2; i <= n;i++)
		//{
		//	m = a + b;
		//	a = b;
		//	b = m;
		//}
		//return m;

		//递归
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		return Fibonacci(n - 1) + Fibonacci(n - 2);

	}//end Fibonacci
};


int main()
{


	return 0;
}
#endif


//跳台阶
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法
（先后次序不同算不同的结果）。
*/
#if 0
#include<iostream>

class Solution
{
public:
	int jumpFloor(int number)
	{

	}
};


int main()
{


	return 0;
}
#endif