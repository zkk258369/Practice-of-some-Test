#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (nums[mid] > target) {
            return mid;
        } else {
            return mid + 1;
        }
    }
};

int main()
{
    Solution s1;
	int target = 2;
	// int num[] = { -1,0,3,5,9,12 };
    int num[] = {1,3,5,6};

	vector<int> nums(num, num + 4);

	int ans = s1.searchInsert(nums, target);
    std::cout << ans << std::endl;
    return 0;
}