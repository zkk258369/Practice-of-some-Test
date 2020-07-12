#include<bits/stdc++.h>
using namespace std;

/*
 * 问题1：sizeof(str) 和 strlen(str) 的区别？
 *     sizeof(str) 会计算str所占总空间的字节数，
 *    strlen(str)会计算字符串的有效长度，不包括'\0'
*/

/*
 * 问题2： strcpy 和 strncpy 的区别？
 *     区别是strncpy有参数控制拷贝的个数，
 *    不像strcpy，strncpy不会向dest追加结束标记'\0'
*/

/*
 * 问题3： strcpy 和 strncpy 函数为什么要返回dest的副本？
 *     为了实现函数连级使用   strcpy(str3, strcpy(str1,str2)) 
*/

/*
 * 问题4： strcpy 和 strncpy 函数的缺陷有哪些？你如何解决？有替代函数吗？
 *     strcpy函数缺陷：
 *                   要程序员保证dest大小能够存放src包括'\0',
 *                  一旦dest空间不够会在别的内存中写入，很危险。可能有覆盖问题
 *     strncpy函数缺陷：
 *                    如果src的前n个字符不包含'\0'字符，
 *                   strncpy函数不会在末尾补上'\0'，打印时会有乱码。
 *                    如果src的长度小于n个字节，则以'\0'填充dest直到复制完n个字节，
 *                   如果n远大于src这会导致效率问题。可能有覆盖问题
 *     正确使用这两个函数：
 *                      使用strcpy时人工确定dest大小足够；
 *                     使用strncpy时，确保 n = dest - 1.
 *     替代函数：memmove(),解决src可能被覆盖问题
*/

/*
* 将src拷贝到dest中，包括'\0'字符
* 为避免溢出dest指向的空间应该足够大能够放的下src
*/
char* my_strcpy(char* dest, const char* src)
{
	//assert(dest != NULL && src != NULL);
	char* save = dest;
	while ((*dest++ = *src++) != '\0');
	return save;
}

/*
* 如果src的前n个字节不含'\0'字符，则结果不会以'\0'字符结束。
* 如果src的长度小于n个字节，则以'\0'填充dest直到复制完n个字节。
* 如果src中有'\0',例如："abc\0def" 则只会复制abc
* src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*
* strncpy 的标准用法为：（手工写上 \0）
*   strncpy(path, src, sizeof(path) - 1);
*   path[sizeof(path) - 1] = '\0';
*/
char* my_strncpy(char* dest, const char* src, size_t count)
{
	//assert(dest != NULL && src != NULL);
	char* save = dest;
	while (count--)
	{
		if (*src != '\0') *dest++ = *src++;
		else *dest++ = '\0';
	}
	return save;
}

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest != nullptr && src != nullptr);
	char* p = (char*)dest;
	char* q = (char*)src;
	if (p == q) return p;
	while (count--)
	{
		*p++ = *q++;
	}
	return dest;
}

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	if (dest < src || (char*)dest >= ((char*)src + count)) // dest尾巴可能和src头部重合
	{                                                      // 或者dest > src,但是src+count没有与dest头部重合
		char* p = (char*)dest;
		char* q = (char*)src;
		while (count--)
		{
			*p++ = *q++;
		}
	}
	else            // src尾部可能和dest头部重合 
	{
		char* p = (char*)dest + count;
		char* q = (char*)src + count;
		while (count--)
		{
			*--p = *--q;
		}
	}
	return dest;
}

int main()
{
	// 测试 strlen 和 sizeof
	char str[] = { "yhp\0ing hello" };
	int len1 = strlen(str);  // 12
	int len2 = sizeof(str);  // 13
	cout << len1 << endl;
	cout << len2 << endl;

	// 测试 my_strcpy 和 my_strncpy
	char dest[20];
	my_strcpy(dest, str);
	my_strncpy(dest, str, 15);
	cout << dest << endl;

	// 测试 my_memcpy 和 my_memmove
	char s1[] = "123456789";
	char s2[] = "123456789";
	my_memcpy(s1 + 2, s1, 5);
	cout << "my_memcpy: " << s1 << endl;
	my_memmove(s2 + 2, s2, 5);
	cout << "my_memmove: " << s2 << endl;


	system("pause");
	return 0;
}