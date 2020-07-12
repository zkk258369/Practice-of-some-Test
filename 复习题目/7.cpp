#include<iostream>
using namespace std;

/*
 *  参考：https://blog.csdn.net/qq_32252957/article/details/83054183
 *  UTF-8编码表：
 *  U-00000000 - U-0000007F : 0xxxxxxx
 *  U-00000080 - U-000007FF : 110xxxxx 10xxxxxx
 *  U-00000800 - U-0000FFFF : 1110xxxx 10xxxxxx 10xxxxx
 *  U-00010000 - U-001FFFFF : 11110xxx 10xxxxxx 10xxxxxxx 10xxxxxx
 *  U-00200000 - U-03FFFFFF : 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
 *  U-04000000 - U-7FFFFFFF : 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
 *  注意在多字节串中, 第一个字节的开头"1"的数目就是整个串中字节的数目。
 * 而第一行中以0开头，是为了兼容ASCII编码，为一个字节，
 * 第二行就为双字节字符串，第三行为3字节，如汉字就属于这种，以此类推。
*/

/*
 *  判断字节流是否是合法的UTF-8字节流，除了要判断字节开头的格式，
 * 还要判断转换成Unicode字节流后是否满足Unicode字节流的要求，
 * 比如 1100 0001 1000 0000 是合法的UTF-8字节流，
 * 但准换成Unicode字节流后是 0000 0|000 01|00 0000
 * 不满足 大于0x80 并且 小于0x7ff 的条件
*/

union node6
{
	unsigned char a;
	unsigned char al:6;
};

union utf8_Node2
{
	unsigned short a;
	struct
	{
		unsigned short al:6;
		unsigned short ah:5;
	};
};

union utf8_Node3
{
	unsigned short a;
	struct
	{
		unsigned short al:6;
		unsigned short ah:6;
		unsigned short head:4;
	};
};

int calc_utf8_count(unsigned char* data_ptr, unsigned int data_len)
{
	int sum = 0;
	int i = 0;
	while (i<data_len)
	{
		if ((data_ptr[i] >> 7) == 0)
		{
			sum += 1;
			i += 1;
		}
		else if ((i + 2) < data_len && (data_ptr[i] >> 5) == 6 && (data_ptr[i + 1] >> 6) == 2)
		{
			utf8_Node2 node;
			node.a = 0;
			node.ah = data_ptr[i] & 0x1f;
			node.al = data_ptr[i + 1] & 0x3f;
			if (node.a < 0x80 || node.a > 0x7ff) return -1;
			sum += 1;
			i += 2;
		}
		else if ((i + 3) < data_len && (data_ptr[i] >> 4) == 14 && (data_ptr[i + 1] >> 6 == 2 && (data_ptr[i + 2] >> 6) == 2))
		{
			utf8_Node3 node;
			node.a = 0;
			node.head = data_ptr[i] & 0xf;
			node.ah = data_ptr[i + 1] & 0x3f;
			node.al = data_ptr[i + 2] & 0x3f;
			if (node.a < 0x800 || node.a > 0x7fff) return -1;
			sum += 1;
			i += 3;
		}
		else
		{
			sum = -1;
			break;
		}
	}
	return sum;
}


int main()
{
	unsigned char str[10] = { 0 };
	str[0] = 0x62;

	str[1] = 0xc5;
	str[2] = 0x83;

	str[3] = 0xe5;
	str[4] = 0x83;
	str[5] = 0x83;

	str[6] = 0xe6;
	str[7] = 0x83;
	str[8] = 0x83;

	str[9] = 0x63;

	int res = calc_utf8_count(str, 10);
	cout << "res = " << res << endl;  // res = 5

	unsigned char str1[10] = { 0 };
	str1[0] = 0x62;

	str1[1] = 0xc5;
	str1[2] = 0x83;

	str1[3] = 0xe5;
	str1[4] = 0x83;
	str1[5] = 0x83;

	str1[6] = 0xf4; // 1111 0100  error
	str1[7] = 0x83;
	str1[8] = 0x83;

	str1[9] = 0x63;

	int res1 = calc_utf8_count(str1, 10);
	cout << "res1 = " << res1 << endl;  // res1 = -1

	unsigned char str2[10] = { 0 };
	str2[0] = 0x62;

	str2[1] = 0xc1; // 1100 0001 1000 0000  error
	str2[2] = 0x80;

	str2[3] = 0xe5;
	str2[4] = 0x83;
	str2[5] = 0x83;

	str2[6] = 0xe6;
	str2[7] = 0x83;
	str2[8] = 0x83;

	str2[9] = 0x63;

	int res2 = calc_utf8_count(str2, 10);
	cout << "res2 = " << res2 << endl;  // res2 = 5

	return 0;
}