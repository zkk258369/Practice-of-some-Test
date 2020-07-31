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

class Solution // NonRecursive
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vec.resize(n + 1);
        sum = 0;
        int i = 1;
		vec[i] = 0;
		while (i > 0)
		{
			if (i <= n) vec[i] += 1;
			while (i <= n && vec[i] <= n && !Place(i)) vec[i] += 1;
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
				i--;
			}
			else if (vec[i] > n) i--;
			else
			{
				i++;
				if(i <= n) vec[i] = 0;
			}
		}
        return chessBoard;
    }
private:
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
    vector<vector<string>> chessBoard;
    vector<int> vec;
    int sum;
};