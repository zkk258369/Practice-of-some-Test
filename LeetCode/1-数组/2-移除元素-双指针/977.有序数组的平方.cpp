#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int i = 0, j = nums.size() - 1, pos = nums.size() - 1;

        while (i <= j) {
            int productI = nums[i] * nums[i];
            int productJ = nums[j] * nums[j];
            if (productI > productJ) {
                res[pos] = productI;
                i++;
            } else {
                res[pos] = productJ;
                j--;
            }
            pos--;
        }

        return res;
    }
};

int main()
{
    Solution s1;
    int num[] = {-4};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    vector<int> ans = s1.sortedSquares(nums);
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}