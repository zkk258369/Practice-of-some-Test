#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    void perm(vector<int>& nums, int k, int m, vector<vector<int>>& res)
    {
        if(k == m)
        {
            res.push_back(nums);
        }
        else
        {
            int j = k;
            while(j <= m)
            {
                swap(nums[j], nums[k]);
                perm(nums, k+1, m, res);
                swap(nums[j], nums[k]);
                j++;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        perm(nums, 0, nums.size()-1, res);
        return res;
    }
};

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int len = sizeof(arr) / sizeof(arr[0]);

	vector<int> vec(arr, arr + 3);
    Solution s;
	vector<vector<int>> res = s.permute(vec);

	return 0;
}