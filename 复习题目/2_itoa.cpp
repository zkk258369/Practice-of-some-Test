#include<bits/stdc++.h>
using namespace std;

/*
 * 功能：将整型数值转换为字符串
 *
 * 参数说明：
 * value：  欲转换的数值。
 * buffer： 目标字符串的地址。
 * radix：  转换后的进制数，可以是2进制，10进制、16进制等。
 *
 * 不考虑value为负数
 *
 * 与函数sprintf()比较：
 * 1.都可以将十进制数字准换从十六进制数字
 * 2.sprintf()函数可以按照 格式化字符串 输出八进制或者16进制数字，或者其他格式的数字，但不能直接转换成二进制，而itoa()函数可以。
*/

//value = 0
//radix > 10 + 26 || radix < 2
char* my_itoa(int value, char* buffer, int radix)
{
	char stra[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char strA[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str[65] = "\0";
	int num = value;
	int i = 0;
	int j = 0;
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return buffer;
	}
	if (radix >= 2 && radix <= strlen(stra))
	{
		while (num != 0)
		{
			str[i++] = stra[num % radix];
			num /= radix;
		}
		str[i] = '\0';
		while (i >= 0) buffer[j++] = str[--i];
	}
	buffer[j] = '\0';

	return buffer;
}

int main()
{
	char str[50];
	int value = 15;
	int radix = 10;
	my_itoa(value, str, radix);
	cout << str << endl;

	char string[100];

	sprintf(string, "%x", 32);
	cout << string << endl;

	system("pause");
	return 0;
}