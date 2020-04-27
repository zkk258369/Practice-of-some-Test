#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        int x = 0;
        for(int i = matrix.size()-1; i>=0; --i)
        {
            for(int j = x; j<matrix[i].size(); ++j)
            {
                if(matrix[i][j] > target) break;
                else if(matrix[i][j] == target) return true;
                else ++x;
            }
        }
        return false;
    }
};