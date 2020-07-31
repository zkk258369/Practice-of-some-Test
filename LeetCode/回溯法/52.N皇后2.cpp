#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        vec.resize(n + 1);
        sum = 0;
        Backtrack(1, n);
        return sum;
    }
private:
	void Backtrack(int i, int n)
	{
		if (i > n) sum += 1;
		else
		{
			for (int j = 1; j <= n; j++)
			{
				vec[i] = j;
				if (Place(i)) Backtrack(i + 1, n);
			}
		}
	}
	bool Place(int row)
	{
		for (int i = 1; i < row; i++)
		{
			if (vec[row] == vec[i] || abs(vec[i] - vec[row]) == abs(i - row))
            {
                return false;
            }
		}
		return true;
	}
private:
    vector<int> vec;
    int sum;
};