/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

1.常规方法遍历数组即可找到。时间复杂度O(n)
2.数组有序，考虑二分查找。
处理特例：
整个数组都有序
二分查找中indexFirst,indexLast,indexMid三个指向的数字相同
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
		int indexMid = indexFirst;//解决数组本来全部有序
		while (rotateArray[indexFirst] >= rotateArray[indexLast])
		{
			if (indexLast - indexFirst == 1)
			{
				indexMid = indexLast;
				break;
			}
			indexMid = (indexFirst + indexLast) / 2;

			//如果indexFirst,indexLast,indexMid三个指向的数字相同
			//则只能顺序查找
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
	}//end minNumberInRotateArray按顺序查找
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
