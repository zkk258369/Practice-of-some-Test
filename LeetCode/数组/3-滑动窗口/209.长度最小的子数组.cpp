#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

// 暴力
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int res = len + 1;
        int i = 0;
        int j = i;
        for (i = 0; i < len; i++) {
            int sum = 0;
            for (j = i; j < len; j++) {
                sum += nums[j];
                if (sum >= target) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == len + 1 ? 0 : res;
    }
};

// 前缀和 + 二分查找
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int res = len + 1;

        vector<int> sums(len + 1, 0);
        sums[0] = nums[0];
        for (int i = 1; i <= len; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= len; i++) {
            int s = target + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), s);
            if (bound != sums.end()) {
                res = min(res, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return res == len + 1 ? 0 : res;
    }
};

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int res = len + 1;

        int start = 0, end = 0;
        int sum = 0;
        while (end < len) {
            sum += nums[end];
            while(sum >= target){
                res = min(res, end-start+1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return res == len + 1 ? 0 : res;
    }
};

int main()
{
    Solution2 s1;
    int num[] = {1,2,3,4,5};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    int ans = s1.minSubArrayLen(15, nums);
    std::cout << ans << std::endl;
    return 0;
}