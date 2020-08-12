#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution // KahnTopological
{
public:
	bool canFinish(int num, vector<vector<int>>& pre)
	{
		vector<int> res;
		vector<int> indegree(num);
		for (int i = 0; i < pre.size(); i++)
		{
			indegree[pre[i][0]]++;
		}
		stack<int> sta;
		for (int i = 0; i < num; i++)
		{
			if (indegree[i] == 0) sta.push(i);
		}
		while (!sta.empty())
		{
			int i = sta.top(); sta.pop();
			for (int j = 0; j < pre.size(); j++)
			{
				if (pre[j][1] == i)
				{
					indegree[pre[j][0]]--;
					if (indegree[pre[j][0]] == 0) sta.push(pre[j][0]);
				}
			}
			res.push_back(i);
		}
		if (res.size() != num) return false;
		else return true;
	}
};