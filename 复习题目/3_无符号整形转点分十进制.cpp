#include<bits/stdc++.h>
using namespace std;

/*
 * 功能：将 unsigned int 整型数值转为点分十进制记法表示
 * 点分十进制（Dotted Decimal Notation）
 * 
 * 参数说明：
 * value：欲转换的数数值。
 * buffer：目标字符串的地址。
*/

char* my_DotDec(unsigned int ip, char* buffer)
{
	union IPnode
	{
		unsigned int addr;
		struct
		{
			unsigned char s1, s2, s3, s4;
		};
	};

	IPnode ipnode;
	ipnode.addr = ip;
	sprintf(buffer, "%u.%u.%u.%u", ipnode.s4, ipnode.s3, ipnode.s2, ipnode.s1);
	return buffer;
}

int main()
{
	unsigned int ip = 2148205343;
	char str[30] = "\0";
	my_DotDec(ip, str);
	cout << str << endl;

	system("pause");
	return 0;
}