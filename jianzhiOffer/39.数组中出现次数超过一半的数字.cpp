#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution //排序法
{
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution //摩尔投票法
{
public:
    int majorityElement(vector<int>& nums)
    {
        int votes = 0;
        int x = 0;
        for(int num : nums)
        {
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        int count = 0;
        for(int num : nums)
        {
            if(x == num) count++;
        }
        if(count >= nums.size()/2) return x;
        return -1;
    }
};