#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 思路一
 * 1.先排序
 * 2.递归过程中，遇到nums[i] == nums[i-1]，则跳过这次递归
 *  这样就避免了同层次的相同元素，而没有避免不同层次的相同元素，实现了去重。
*/
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> cur;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        BackTrack(nums, 0, nums.size());
        return res;
    }
    void BackTrack(vector<int>& nums, int index, int n)
    {
        res.push_back(cur);
        for(int i=index; i<n; i++)
        {
            if(i != index && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            BackTrack(nums, i+1, n);
            cur.pop_back();
        }
    }
};

/*思路二
 * 按照 无重复元素子集解法 每次给cur中添加新元素，与原有的元素组合生成新的子集。
 * 示例为 nums = { 1, 2, 2}
 * 第一步：cur = {}, 则res = { { } }
 * 第二步：添加元素nums[0]，则res = { { }, {1} }
 * 第三步：添加元素nums[1]，则res = { { }, {1}, {2}, {1, 2} }
 * 第四步：添加元素nums[2]，则res = { { }, {1}, {2}, {1, 2}, {2}, {1, 2}, {2, 2}, {1, 2, 2} }
 * 我们发现添加重复元素时，还会与第三步的旧解res = { { }, {1} }生成{ {2}, {1, 2} }，
 *  会与第三步的新解{ {2}, {1, 2} }重复，我们发现这个规律后，
 *  就设置遍历left，right记录前一步的新解，即记录第三步中的{ { }, {1} }，
 *  每次添加重复元素时，只与前一步的新解组合。
*/

class Solution
{
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        int left = 0;
        int right = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int start = 0;
            int end = res.size() - 1;
            if(i != 0 && nums[i] == nums[i-1])
            {
                start = left;
                end = right;
            }
            left = res.size();
            for(int j=start; j<=end; j++)
            {
                vector<int> cur = res[j];
                cur.push_back(nums[i]);
                res.push_back(cur);
            }
            right = res.size() - 1;
        }
        return res;
    }
};