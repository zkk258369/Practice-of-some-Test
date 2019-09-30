/*
给定一个整数数组 nums 和一个目标值 target
请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<iterator>

using std::vector;


//暴力法
//class Solution
//{
//public:
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		vector<int> ansArr(2, -1);
//		for (int i = 0; i < nums.size();i++)
//		{
//			int j = i + 1;
//			for (; j < nums.size();j++)
//			{
//				if (nums[i] + nums[j] == target)
//				{			
//					ansArr[0] = i;
//					ansArr[1] = j;
//					break;
//				}				
//			}
//		}
//		return ansArr;
//		throw "no answer";
//	}
//};

//哈希表
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ansArr(2, -1);
		std::unordered_map<int, int> record;//创建哈希表
		for (int i = 0; i < nums.size(); i++)
		{
			int tmp = target - nums[i];
			if (record.find(tmp) != record.end())
			{
				ansArr[0] = i;
				ansArr[1] = record[tmp];
				break;
			}
			record[nums[i]] = i;
		}
		return ansArr;
	}
};


int main()
{
	Solution s1;
	int target = 9;
	int num[] = { 2, 7, 11, 15 };

	vector<int> nums(num, num + 2);
	vector<int> ans(2, -1);
	ans = s1.twoSum(nums, target);

	std::ostream_iterator<int> out(std::cout, " ");
	copy(ans.begin(), ans.end(),out);
	std::cout << std::endl;
	system("pause");

	return 0;
}