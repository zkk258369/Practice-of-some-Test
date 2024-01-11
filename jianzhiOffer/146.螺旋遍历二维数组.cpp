#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.size() == 0 || array[0].size() == 0) {
            return vector<int>{};
        }
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rows = array.size(), cols = array[0].size();

        int directionIndex = 0;
        vector<vector<bool>> visit(rows, vector<bool>(cols));
        int n = rows * cols;
        vector<int> res(n);
        int cnt = 0;
        int row = 0, col = 0;
        while (cnt < n) {
            res[cnt++] = array[row][col];
            visit[row][col] = true;
            int nextrow = row + directions[directionIndex][0];
            int nextcol = col + directions[directionIndex][1];
            if (nextrow < 0 || nextrow >= rows || nextcol < 0 ||
                nextcol >= cols || visit[nextrow][nextcol]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row = row + directions[directionIndex][0];
            col = col + directions[directionIndex][1];
        }
        return res;
    }
};