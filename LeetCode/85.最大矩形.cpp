#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution  // 动态规划 - 使用柱状图的优化暴力方法
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> dp(row, vector<int>(col));
        for(int i=0; i < row; i++)
        {
            for(int j=0; j < col; j++)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = j==0 ? 1 : dp[i][j-1] + 1;
                    int width = dp[i][j];
                    for(int k=i; k >= 0; k--)
                    {
                        width = min(width, dp[k][j]);
                        maxArea = max(maxArea, width * (i-k+1));
                    }
                }
            }
        }
        return maxArea;
    }
};

class Solution  // 使用柱状图 - 栈
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        int maxArea = 0;
        vector<int> dp(col);
        for(int i=0; i < row; i++)
        {
            for(int j=0; j < col; j++)
            {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(dp));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights)
	{
		int res = 0;
		int n = heights.size();
		vector<int> minLeft(n);
		vector<int> minRight(n, n);
		stack<int> mono_stack;

		for (int i = 0; i<n; i++)
		{
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
			{
				minRight[mono_stack.top()] = i;
				mono_stack.pop();
			}
			minLeft[i] = mono_stack.empty() ? -1 : mono_stack.top();
			mono_stack.push(i);
		}
		// find maxArea
		for (int i = 0; i<n; i++)
		{
			res = max(res, heights[i] * (minRight[i] - minLeft[i] - 1));
		}
		return res;
	}
};

class Solution
{
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();
		int maxArea = 0;
		vector<int> height(col);
		vector<int> left(col);
		vector<int> right(col, col);
		for (int i = 0; i < row; i++)
		{
			int cur_left = 0;
			int cur_right = col;
			//update height
			for (int j = 0; j<col; j++)
			{
				if (matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			for (int j = 0; j<col; j++)
			{
				if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
				else { left[j] = 0; cur_left = j + 1; }
			}
			for (int j = col - 1; j >= 0; j--)
			{
				if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
				else { right[j] = col; cur_right = j; }
			}
			for (int j = 0; j<col; j++)
			{
				maxArea = max(maxArea, height[j] * (right[j] - left[j]));
			}
		}
		return maxArea;
	}
};