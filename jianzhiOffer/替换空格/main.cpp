/*
��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20��.
�������롰we are happy��,�������we%20are%20happy��.

���������֣�һ������ԭ�����ַ��������滻����һ�����Լ�����һ���µ��ַ�����
���µ��ַ��������滻��
	�����Ŀ�򵥣����ƴ�Ҷ�����ɣ���Ҫ���ʣ���Ҫ���Ż�
	ʱ�临�Ӷȵ��Ż�
*/
//O^2�Ľⷨ��
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
				//���ո������ַ�������ƶ�����λ��
				for (int j = strlen(str); j > i; j--){
					str[j + 2] = str[j];
				}
				//�滻�ո�
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
�Ż���
�ȼ���ո�������������ָ�룬p1ָ��ԭ���ַ���β����p2ָ���޸ĺ�β��
�Ӻ���ǰ�滻�ո�
������һЩ�ַ����ƶ��Ĵ���
*/
class Solution{
public:
	void replaceSpace(char *str, int length) {
		//�������Թ�����ԭ���������޸��ַ���
		int spaceNum = 0;
		int i = 0;
		while (str[i] != '\0'){

			if (str[i++] == ' ')
				spaceNum++;
		}
		int newLength = i + 2 * spaceNum;//�滻���ַ������ܴ�С
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
