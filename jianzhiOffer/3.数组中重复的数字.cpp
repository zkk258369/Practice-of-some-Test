#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        std::ios::sync_with_stdio(false);//取消cin,cout和stdio同步，可提速程序
        for (int i = 0; i < nums.size(); i++)
        {    
            while (nums[i] != i) 
            {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};