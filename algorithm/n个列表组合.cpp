#include<iostream>
#include<vector>
using namespace std;

//n个列表组合
void Perm(vector<vector<int>>& arr, int k, vector<int>& tmp, vector<vector<int>>& res)
{
	if (k == arr.size())
	{
		res.push_back(tmp);
	}
	else
	{
		for (int i = 0; i < arr[k].size(); i++)
		{
			tmp.push_back(arr[k][i]);
			Perm(arr, k + 1, tmp, res);
			tmp.pop_back();
		}
	}
}

int main()
{
	vector<vector<int>> vec = { { 1, 2, 3 }, { 4, 5 }, { 6, 7, 8, 9 } };
	vector<vector<int>> res;
	vector<int> tmp;
	Perm(vec, 0, tmp, res);
	for (auto it : res)
	{
		for (auto i : it)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}