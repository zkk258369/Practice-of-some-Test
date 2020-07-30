#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vec.resize(n + 1);
        sum = 0;
        Backtrack(1, n);
        return chessBoard;
    }
private:
	void Backtrack(int i, int n)
	{
		if (i > n)
		{
            sum += 1;
            chessBoard.resize(sum);
			for (int row = 1; row <= n; row++)
			{
                string str;
				for (int col = 1; col <= n; col++)
				{
					if (vec[row] == col) str.push_back('Q');
					else str.push_back('.');
				}
                chessBoard[sum-1].push_back(str);
			}
		}
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
    vector<vector<string>> chessBoard;
    vector<int> vec;
    int sum;
};