#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if (nums[i] > 0) break;
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            if (nums[i] + nums[len-2] + nums[len-1] < 0) continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                } else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s1;
    int num[] = {-1,0,1,2,-1,-4};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);
    vector<vector<int>> res = s1.threeSum(nums);

    return 0;
}