#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;
        bool first = false;
        int first_mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                res[0] = mid;
                right = mid - 1;
                if (first) {
                    first_mid = mid;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        right = len - 1;
        left = first_mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                res[1] = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s1;
    int target = 1;
    int num[] = {1};
    vector<int> nums(num, num + 1);
    vector<int> res = s1.searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}