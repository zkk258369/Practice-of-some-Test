#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int up = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (left <= right && up <= bottom) {
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[up][j]);
            }
            for (int i = up + 1; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if (left < right && up < bottom) {
                for (int j = right - 1; j > left; j--) {
                    res.push_back(matrix[bottom][j]);
                }
                for (int i = bottom; i > up; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++; right--;
            up++; bottom--;
        }
        return res;
    }
};

class Solution2 {
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};

int main()
{
    Solution s1;
    vector<vector<int>> matrix(1, vector<int>(2, -1));
    matrix[0][0] = 3;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[1][0] = 5;
    matrix[1][1] = 6;
    matrix[1][2] = 7;
    matrix[1][3] = 8;
    matrix[2][0] = 9;
    matrix[2][1] = 10;
    matrix[2][2] = 11;
    matrix[2][3] = 12;
    vector<int> ans = s1.spiralOrder(matrix);
    for (int a : ans) {
        std::cout << a << " ";
    }
    // std::cout << ans << std::endl;
    
    return 0;
}