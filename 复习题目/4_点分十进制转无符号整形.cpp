#include<bits/stdc++.h>
using namespace std;

/*
 * 功能：将点分十进制表示的字符串转换为 unsigned int 整型数值
 *
 * 参数说明：strip 点分十进制表示的字符串
*/

unsigned int my_ResDotDec(const char* strip)
{
	union IPnode
	{
		unsigned int addr;
		struct
		{
			unsigned char s[4];
		};
	};
	IPnode ipnode;
	ipnode.addr = UINT_MAX;
	char str[30] = "\0";
	strcpy(str, strip);
	char* p = strtok(str, ".");
	int i = 3;
	while (p != nullptr && i >= 0)
	{
		int tmp = atoi(p);
		if (tmp > 255) return UINT_MAX;
		else ipnode.s[i--] = tmp;
		p = strtok(nullptr, ".");
	}
	if (p != nullptr || i >= 0) return UINT_MAX;
	return ipnode.addr;
}

int main()
{
	char str[][30] = {"128.11.3.31",
					"128.11.3.31.4.3.3",
					"12.3.4",
					"",
					"128.399.2.12"};
	int len = sizeof(str)/sizeof(str[0]);
	for(int i=0; i<len; i++)
	{
		unsigned int res = my_ResDotDec(str[i]);
		cout << str[i] << " -> " << res << endl;
	}
	
	cout << "UINT_MAX = " << UINT_MAX << endl;

	system("pause");
	return 0;
}