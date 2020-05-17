/*
大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。0 <= n <= 100
1.递归虽然容易写，但又效率问题
2.先算出f(0),f(1),f(2)…依次往下计算，直到算出我们所需要的f(n),时间复杂度为O(n)
3.时间复杂度为O(logn)的解法，一般不实用，但可以用来炫技。基于矩阵乘法。
*/

#include<bits/stdc++.h>

class Solution // 矩阵乘法 时间复杂度O(logn)
{
public:
	int fib(int n)
	{
		int res[2] = {0, 1};
		if(n < 2) return res[n];
		else
		{
			Matrix2By2 ans = MatrixPower(n-1);
			return ans.m_00 % MOD;
		}
	}
private:
    const int MOD = 1000000007;
	struct Matrix2By2
	{
		Matrix2By2
		(
			long long m00 = 0, long long m01 = 0, 
			long long m10 = 0, long long m11 = 0
		) :m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}

		long long m_00; long long m_01;
		long long m_10; long long m_11;
	};
	Matrix2By2 MatrixMultiply(const Matrix2By2& m1, const Matrix2By2& m2)
	{
		return Matrix2By2(
		(m1.m_00 * m2.m_00) % MOD + (m1.m_01 * m2.m_10) % MOD,
        (m1.m_00 * m2.m_01) % MOD + (m1.m_01 * m2.m_11) % MOD,
        (m1.m_10 * m2.m_00) % MOD + (m1.m_11 * m2.m_10) % MOD,
        (m1.m_10 * m2.m_01) % MOD + (m1.m_11 * m2.m_11) % MOD
		);
	}
	Matrix2By2 MatrixPower(unsigned int n)
	{
		Matrix2By2 matrix;
		if(n == 1)
		{
			matrix = Matrix2By2(1, 1, 1, 0);
		}
		else if(n % 2 == 0)
		{
			matrix = MatrixPower(n / 2);
			matrix = MatrixMultiply(matrix, matrix);
		}
		else if(n % 2 == 1)
		{
			matrix = MatrixPower((n - 1) / 2);
			matrix = MatrixMultiply(matrix, matrix);
			matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
		}
		return matrix;
	}
};

class Solution2 // 时间复杂度O(n)
{
public:
	int Fibonacci(int n)
	{
		if (n == 0) return 0;
		if (n == 1) return 1;
		int a = 0;
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

class Solution1 // 递归
{
public:
	int Fibonacci(int n)
	{
		if (n == 0) return 0;
		if (n == 1) return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};