/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
解题思路：
	1.设置一个标志flag = 1，与n进行与运算，结果为真则说明最后一位是1，
则count++,之后将flag左移一位，与n的倒数第二位进行与运算，
进行循环，直到flag为0。然后返回count的值。
	2.n减一，与原来的数进行与运算，得到的数比原来的n少了最右边的1，
	利用这个性质解题。

*/
#include<iostream>

class Solution {
public:
	//左移flag
	int  NumberOf1(int n) {
		unsigned int flag = 1;
		int count = 0;
		while (flag)
		{
			if (flag & n)
				count++;
			flag = flag << 1;
		}
		return count;
	}

	//有多少个一便循环几次
	int  NumberOf1(int n) {
		int count = 1;
		while (n)
		{
			n = (n - 1) & n;
			count++;
		}
		return count;
	}
};


int main()
{
	return 0;
}