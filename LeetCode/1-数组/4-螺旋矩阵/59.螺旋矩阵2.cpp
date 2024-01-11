#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        int left=0, right=n-1;
        int top=0, bottom=n-1;
        int cnt=1;
        while(left<=right && top<=bottom) {
            for(int j=left; j<=right; j++) {
                matrix[top][j]=cnt++;
            }
            for (int i=top+1; i<=bottom; i++) {
                matrix[i][right]=cnt++;
            }
            if (left<right && top<bottom) {
                for (int j=right-1; j>left; j--) {
                    matrix[bottom][j]=cnt++;
                }
                for (int i=bottom; i>top; i--) {
                    matrix[i][left]=cnt++;
                }
            }
            left++; right--;
            top++; bottom--;
        }
        return matrix;
    }
};

int main()
{
    Solution s1;

    vector<vector<int>> ans = s1.generateMatrix(5);
    // std::cout << ans << std::endl;
    
    return 0;
}