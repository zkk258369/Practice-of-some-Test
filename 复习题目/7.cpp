#if 1
#include<iostream>
#include<string.h>
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
 * 不满足 大于0x80 并且 小于0x7ff 的条件，所以不是合法的UTF-8字节流
*/

union GSutf8_8  // char  // Get Set
{
	wchar_t code;
	char ch[1];
};
union Gutf8_16 // 2char
{
	wchar_t code; // 2
	struct
	{
		unsigned short al : 6;
		unsigned short ah : 5;
	};
};
union Sutf8_16
{
	unsigned char data[2];
	struct
	{
		unsigned short ah : 5;
		unsigned short tagh : 3;
		unsigned short al : 6;
		unsigned short tagl : 2;
	};
};
union Gutf8_24
{
	wchar_t code;
	struct
	{
		unsigned short al : 6;
		unsigned short ah : 6;
		unsigned short hh : 4;
	};
};
union Sutf8_24
{
	unsigned char data[3];
	struct
	{
		unsigned char hh : 4;
		unsigned char taghh : 4;
		unsigned char ah : 6;
		unsigned char tagh : 2;
		unsigned char al : 6;
		unsigned char tagl : 2;
	};
};

int Unicode_to_UTF8(wchar_t* code, int len, unsigned char* buffer)
{
	int i = 0;
	int j = 0;
	while (i<len)
	{
		if (code[i] >= 0x0000 && code[i] <= 0x007f)
		{
			GSutf8_8 x;
			x.code = code[i];
			memcpy(buffer + j, x.ch, 1);
			j += 1;
		}
		else if (code[i] >= 0x0080 && code[i] <= 0x07ff)
		{
			Gutf8_16 x;
			Sutf8_16 y;
			x.code = code[i];
			y.al = x.al;
			y.tagl = 2; // 10
			y.ah = x.ah;
			y.tagh = 6; // 110;
			memcpy(buffer + j, y.data, 2);
			j += 2;
		}
		else
		{
			Gutf8_24 x;
			Sutf8_24 y;
			x.code = code[i];
			y.al = x.al;
			y.tagl = 2; // 10;
			y.ah = x.ah;
			y.tagh = 2; // 10;
			y.hh = x.hh;
			y.taghh = 14; // 1110 
			memcpy(buffer + j, y.data, 3);
			j += 3;
		}
		++i;
	}
	j += 1;
	buffer[j] = '\0';
	return j - 1;
}

wchar_t UTF8_to_Unicode(unsigned char* str, int len) // len=1 , len=2 , len=3
{
	if (len < 1 || len > 3) return 0xffff;
	if (len == 1)
	{
		GSutf8_8 x = { 0 };
		x.ch[0] = str[0];
		return x.code;
	}
	else if (len == 2)
	{
		Sutf8_16 x = { 0 };
		x.data[0] = str[0];
		x.data[1] = str[1];
		Gutf8_16 y = { 0 };
		y.al = x.al;
		y.ah = x.ah;
		return y.code;
	}
	else if (len == 3)
	{
		Sutf8_24 x = { 0 };
		x.data[0] = str[0]; x.data[1] = str[1]; x.data[2] = str[2];
		Gutf8_24 y = { 0 };
		y.al = x.al;
		y.ah = x.ah;
		y.hh = x.hh;
		return y.code;
	}
}

int Calc_UTF8_Count(unsigned char* data_ptr, unsigned int data_len)
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
			wchar_t wc = UTF8_to_Unicode(data_ptr + i, 2);
			if (wc < 0x0080 || wc > 0x07ff) return -1;
			sum += 1;
			i += 2;
		}
		else if ((i + 3) < data_len && (data_ptr[i] >> 4) == 14 && (data_ptr[i + 1] >> 6 == 2 && (data_ptr[i + 2] >> 6) == 2))
		{
			wchar_t wc = UTF8_to_Unicode(data_ptr + i, 3);
			if (wc < 0x0800 || wc > 0xFFFF) return -1;
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
	unsigned char buffer[256] = { 0 };
	wchar_t x[] = { L"yhp杨和平hello" }; // L指定为Unicode字符串
	int n = sizeof(x) / sizeof(x[0]) - 1;
	cout << "n = " << n << endl;

	cout << "x = " << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;

	int len = Unicode_to_UTF8(x, n, buffer);
	cout << "len = " << len << endl;
	cout << "buffer = " << buffer << endl;

	len = Calc_UTF8_Count(buffer, len);
	cout << "len = " << len << endl;

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

	int res = Calc_UTF8_Count(str, 10);
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

	int res1 = Calc_UTF8_Count(str1, 10);
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

	int res2 = Calc_UTF8_Count(str2, 10);
	cout << "res2 = " << res2 << endl;  // res2 = 5

	return 0;
}
#endif