/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
����˼·��
	1.����һ����־flag = 1����n���������㣬���Ϊ����˵�����һλ��1��
��count++,֮��flag����һλ����n�ĵ����ڶ�λ���������㣬
����ѭ����ֱ��flagΪ0��Ȼ�󷵻�count��ֵ��
	2.n��һ����ԭ���������������㣬�õ�������ԭ����n�������ұߵ�1��
	����������ʽ��⡣

*/
#include<iostream>

class Solution {
public:
	//����flag
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

	//�ж��ٸ�һ��ѭ������
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