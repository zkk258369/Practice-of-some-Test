/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n��
�������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
1.�ݹ���Ȼ����д������Ч������
2.�����f(0),f(1),f(2)���������¼��㣬ֱ�������������Ҫ��f(n),ʱ�临�Ӷ�ΪO(n)
3.ʱ�临�Ӷ�ΪO(logn)�Ľⷨ��һ�㲻ʵ�ã������������ż�
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

		//�ݹ�
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


//��̨��
/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж���������
���Ⱥ����ͬ�㲻ͬ�Ľ������
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