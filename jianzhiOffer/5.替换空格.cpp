/*
题目：请实现一个函数，把字符串中的每个空格替换成“%20”.
例如输入“we are happy”,则输出“we%20are%20happy”.

方法有两种，一个是在原来的字符串上做替换，另一个是自己创建一个新的字符串，
在新的字符串上做替换。
	这个题目简单，估计大家都能完成，想要出彩，就要做优化
	时间复杂度的优化
*/
//O^2的解法：
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL){
			return;
		}
		char space[4] = "%20";
		int i;
		for (i = 0; str[i] != '\0'; i++){
			if (str[i] == ' '){
				//将空格后面的字符串向后移动两个位置
				for (int j = strlen(str); j > i; j--){
					str[j + 2] = str[j];
				}
				//替换空格
				for (int j = i, k = 0; k < 3; j++){
					str[j] = space[k++];
				}
				i += 2;
			}
		}
		str[i] = '\0';
	}
};


/*
优化：
先计算空格数，设置两个指针，p1指向原来字符串尾部，p2指向修改后尾部
从后往前替换空格；
减少了一些字符被移动的次数
*/
class Solution{
public:
	void replaceSpace(char *str, int length) {
		//假设面试官让在原来基础上修改字符串
		int spaceNum = 0;
		int i = 0;
		while (str[i] != '\0'){

			if (str[i++] == ' ')
				spaceNum++;
		}
		int newLength = i + 2 * spaceNum;//替换后字符串的总大小
		char* p1 = str + i;
		char* p2 = str + newLength;
		while (p1 < p2){
			if (*p1 == ' '){
				*(p2--) = '0';
				*(p2--) = '2';
				*(p2--) = '%';
			}
			else{
				*(p2--) = *p1;
			}
			p1--;
		}
	}
};
