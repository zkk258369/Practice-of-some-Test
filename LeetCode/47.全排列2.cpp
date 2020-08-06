#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        n = nums.size();
        TrackBack(nums, 0, n-1);
        return res;
    }
    void TrackBack(vector<int>& nums, int k, int m)
    {
        if(k == m)
        {
            res.push_back(nums);
        }
        set<int> setSwap;
        for(int j=k; j<=m; j++)
        {
            if(setSwap.find(nums[j]) != setSwap.end())
            {
                continue;
            }
            setSwap.insert(nums[j]);
            swap(nums[j], nums[k]);
            TrackBack(nums, k+1, m);
            swap(nums[j], nums[k]);
        }
    }
};