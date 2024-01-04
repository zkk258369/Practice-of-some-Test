#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    }
};

int main()
{
    Solution s1;
    int num[] = {2,3,1,2,4,3};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    int ans = s1.minSubArrayLen(7, nums);
    std::cout << ans << std::endl;
    return 0;
}