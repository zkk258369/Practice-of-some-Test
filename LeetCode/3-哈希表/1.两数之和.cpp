#include<iostream>
#include<unordered_map>
#include<vector>
#include<iterator>
#include<algorithm>

using std::vector;


//暴力法 200ms
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ansArr(2, -1);
		for (int i = 0; i < nums.size();i++) {
			int j = i + 1;
			for (; j < nums.size();j++) {
				if (nums[i] + nums[j] == target) {			
					ansArr[0] = i;
					ansArr[1] = j;
					break;
				}				
			}
		}
		return ansArr;
	}
};

// 哈希表 12ms
class Solution2
{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ansArr(2, -1);
		std::unordered_map<int, int> record;//创建哈希表
		for (int i = 0; i < nums.size(); i++) {
			int tmp = target - nums[i];
			if (record.find(tmp) != record.end()) {
				ansArr[0] = i;
				ansArr[1] = record[tmp];
				break;
			}
			record[nums[i]] = i;
		}
		return ansArr;
	}
};

//执行用时为 8 ms 的范例
class Solution3 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> tmp(nums);
		sort(tmp.begin(), tmp.end()); //排序
		int i = 0, j = tmp.size() - 1;
		//排序后，从前后和后面同时开始找
		while (i < j) {
			if (tmp[i] + tmp[j] == target) {
				res.push_back(std::find(nums.begin(), nums.end(), tmp[i]) - nums.begin());
				res.push_back(nums.size() - (std::find(nums.rbegin(), nums.rend(), tmp[j]) - nums.rbegin()) - 1);
				break;
			} else if (tmp[i] + tmp[j] > target) {
				j--;
			} else {
				i++;
			}
		}
		return res;
	}
};


int main()
{
	Solution s1;
	int target = 9;
	int num[] = { 2, 7, 11, 15 };

	vector<int> nums(num, num + 4);
	vector<int> ans(1);

	ans = s1.twoSum(nums, target);

	std::ostream_iterator<int> out(std::cout, " ");
	copy(ans.begin(), ans.end(), out);
	std::cout << std::endl;
	system("pause");

	return 0;
}