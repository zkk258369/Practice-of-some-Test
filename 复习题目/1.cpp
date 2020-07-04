#include<bits/stdc++.h>
using namespace std;

/*
 * 功能：将字符串转换成数字 char* -> int
 * 可以处理正负数
 * 可以处理八进制和十六进制数字
 * 如果溢出或者字符串中没有数字，返回0
*/

int hex(const char* str, int i, bool isPositive)
{
	int res = 0;
	while (str[i] != '\0' && isxdigit(str[i]))
	{
		int num = 0;
		char x = str[i];
		if (isalpha(x))
		{
			x = tolower(str[i]);
			num = x - 'a' + 10;
		}
		else num = str[i] - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7))
		{
			return isPositive ? INT_MAX : INT_MIN;
		}
		res = res * 16 + num;
		i++;
	}
	if (!isPositive) res = -res;
	return res;
}

int oct(const char* str, int i, bool isPositive)
{
	int res = 0;
	while (str[i] != '\0' && isdigit(str[i]) && str[i] != '8' && str[i] != '9')
	{
		int num = str[i] - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7))
		{
			return isPositive ? INT_MAX : INT_MIN;
		}
		res = res * 8 + num;
		i++;
	}
	if (!isPositive) res = -res;
	return res;
}

int dec(const char* str, int i, bool isPositive)
{
	int res = 0;
	while (str[i] != '\0' && isdigit(str[i]))
	{
		int num = str[i] - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7))
		{
			return isPositive ? INT_MAX : INT_MIN;
		}
		res = res * 10 + num;
		i++;
	}
	if (!isPositive) res = -res;
	return res;
}

int my_atoi(const char *str)
{
	int i = 0;
	bool isPositive = true;

	while (str[i] != '\0' && str[i] != '-' && str[i] != '+' && !isdigit(str[i]))
	{
		i++;
	}
	if (str[i] == '\0') return 0;
	if (str[i] == '-')
	{
		isPositive = false;
		i++;
	}
	if (str[i] == '+') i++;

	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x' || str[i] == 'X')  // 转换16进制
		{
			i++;
			return hex(str, i, isPositive);
		}
		else  // 转换8进制
		{
			return oct(str, i, isPositive);
		}
	}
	else  // 转换10进制
	{
		return dec(str, i, isPositive);
	}
}

int main()
{
	char str[][30] = {
		"   234 56.324",
		"   -342ab.234",
		" 0123",
		" -0123",
		"567898765678987656789",
		"-234324665544325345325",
		"2147483647",
		"2147483648",
		"3147483648",
		"4147483648",
		"5147483648",
		"-91283472332",
		"91283472332",
		"2147483649",
		"-2147483647",
		"-2147483648",
		"-2147483649",
		"  +0xff",
		" -0XFF" 
	};
	int len = sizeof(str) / sizeof(str[0]);
	for (int i = 0; i<len; i++)
	{
		int res = my_atoi(str[i]);
		cout << str[i] << " --> " << res << endl;
	}

	system("pause");
	return 0;
}