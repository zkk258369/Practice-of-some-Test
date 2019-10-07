/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

1.���淽���������鼴���ҵ���ʱ�临�Ӷ�O(n)
2.�������򣬿��Ƕ��ֲ��ҡ�
����������
�������鶼����
���ֲ�����indexFirst,indexLast,indexMid����ָ���������ͬ
*/
#include<iostream>
#include<vector>
#include<iterator>

using std::vector;

class Solution {
public:
	int minNumInRotateArray(vector<int> rotateArray)
	{
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		int indexFirst = 0;
		int indexLast = rotateArray.size() - 1;
		int indexMid = indexFirst;//������鱾��ȫ������
		while (rotateArray[indexFirst] >= rotateArray[indexLast])
		{
			if (indexLast - indexFirst == 1)
			{
				indexMid = indexLast;
				break;
			}
			indexMid = (indexFirst + indexLast) / 2;

			//���indexFirst,indexLast,indexMid����ָ���������ͬ
			//��ֻ��˳�����
			if (rotateArray[indexFirst] == rotateArray[indexMid] &&
				rotateArray[indexMid] == rotateArray[indexLast])
				return minNumberInRotateArray(rotateArray);

			if (rotateArray[indexFirst] <= rotateArray[indexMid])
			{
				indexFirst = indexMid;
			}
			else if (rotateArray[indexLast] >= rotateArray[indexMid])
			{
				indexLast = indexMid;
			}
		}//end while
		return rotateArray[indexMid];
	}//end minNumInRotateArray
private:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		std::vector<int>::iterator it = rotateArray.begin();
		while (it != rotateArray.end())
		{
			if (*it > *(it + 1))
			{
				return *(it + 1);
			}
			it++;
		}
	}//end minNumberInRotateArray��˳�����
};


int main()
{
	int arr[] {3, 4, 5, 1, 2};
	vector<int> vec(arr, arr + 5);
	Solution s1;
	int ans = s1.minNumInRotateArray(vec);
	std::cout << ans << std::endl;

	return 0;
}
