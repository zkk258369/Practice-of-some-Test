#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty()) return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while(j >= 0 && i < matrix.size())
        {
            if(matrix[i][j] > target) j--;
            else if(matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};