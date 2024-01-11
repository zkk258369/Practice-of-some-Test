#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int i=0;
        int j=0;
        while (j<len) {
            if (nums[j]) {
                int tmp=nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
            }
            j++;
        }
    }
};

int main()
{
    Solution s1;
    int num[] = {1};
    int len=sizeof(num)/sizeof(num[0]);
	vector<int> nums(num, num + len);

	s1.moveZeroes(nums);
    for (int i=0; i<nums.size(); i++){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}