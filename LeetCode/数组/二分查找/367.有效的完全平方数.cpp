#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right=num;
        int mid=-1;
        while (left<=right) {
            mid = left+ (right-left)/2;
            long long int product = (long long)mid*mid;
            if (product == num) {
                return true;
            } else if (product > num){
                right = mid -1;
            }else {
                left = mid +1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s1;
	int x = 8;

	int ans = s1.isPerfectSquare(x);
    std::cout << ans << std::endl;
    return 0;
}