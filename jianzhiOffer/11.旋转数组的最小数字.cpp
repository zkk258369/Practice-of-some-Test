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
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minArray(vector<int>& arr)
    {
        if(arr.size() == 0) return 0;
        int left = 0;
        int right = arr.size()-1;//[2,2,2,0,1]
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(arr[mid] > arr[right]) left = mid+1;
            else if(arr[mid] < arr[right]) right = mid;
            else right -= 1;
        }
        return arr[left];
    }
};