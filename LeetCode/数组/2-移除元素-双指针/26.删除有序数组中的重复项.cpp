#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 1;
        int j = i;
        for (int i = 1; i < len;) {
            if (nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};

int main()
{
    Solution s1;
    int num[] = {1,1,2};
    int len=sizeof(num)/sizeof(num[0]);
	vector<int> nums(num, num + len);

	int ans = s1.removeDuplicates(nums);
    std::cout << ans << std::endl;
    return 0;
}