#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int len = nums.size();
        int res = nums[0];
        for(int i=1; i<len; i++)
        {
            if(nums[i-1] > 0) nums[i] = nums[i-1] + nums[i];
            else nums[i] = nums[i];
            res = max(res, nums[i]);
        }
        return res;
    }
};