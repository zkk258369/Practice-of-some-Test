#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int l = 0;
        int r = len-1;
        while (l<=r) {
            int mid = (r+l)/2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s1;
	int target = 1;
	// int num[] = { -1,0,3,5,9,12 };
    int num[] = {2,5};

	vector<int> nums(num, num + 2);

	int ans = s1.search(nums, target);
    std::cout << ans << std::endl;
    return 0;
}