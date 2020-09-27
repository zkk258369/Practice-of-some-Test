#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0;
        int b = 0;
        for(int i : nums)
        {
            a = (a^i) & ~b;
            b = (b^i) & ~a;
        }
        return a;
    }
};