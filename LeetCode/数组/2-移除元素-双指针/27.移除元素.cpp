#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        int j = 0;
        for (int i = 0; i < len;) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j;
    }
};

int main()
{
    Solution s1;
	// int num[] = {0,1,2,2,3,0,4,2};
    int num[] = {3,2,2,3};
    int len=sizeof(num)/sizeof(num[0]);
	vector<int> nums(num, num + len);

	int ans = s1.removeElement(nums, 2);
    std::cout << ans << std::endl;
    return 0;
}