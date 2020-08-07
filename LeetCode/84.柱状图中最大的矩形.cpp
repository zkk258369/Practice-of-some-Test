#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution // O(n^2)
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int minLeft = i;
            int minRigh = i;

            int j = i-1;
            for(; j>=0 && heights[j] >= heights[i]; j--);
            minLeft = j;

            j = i+1;
            for(; j<n && heights[j] >= heights[i]; j++);
            minRigh = j;

            res = max(res, heights[i] * (minRigh - minLeft - 1));
        }
        return res;
    }
};

class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		int res = 0;
		int n = heights.size();
		vector<int> minLeft(n);
		vector<int> minRight(n);
		stack<pair<int, int>> sta;

		// find left_height small than heights[i]
		for (int i = 0; i<n; i++)
		{
			while (!sta.empty() && sta.top().second >= heights[i])
			{
				sta.pop();
			}
			if (sta.empty()) minLeft[i] = -1;
			else minLeft[i] = sta.top().first;
			sta.push(pair<int, int>(i, heights[i]));
		}
		// clear stack
		while (!sta.empty()) sta.pop();
		// find right_height small than heights[i]
		for (int i = n - 1; i >= 0; i--)
		{
			while (!sta.empty() && sta.top().second >= heights[i])
			{
				sta.pop();
			}
			if (sta.empty()) minRight[i] = n;
			else minRight[i] = sta.top().first;
			sta.push(pair<int, int>(i, heights[i]));
		}
		// find maxArea
		for (int i = 0; i<n; i++)
		{
			res = max(res, heights[i] * (minRight[i] - minLeft[i] - 1));
		}
		return res;
	}
};