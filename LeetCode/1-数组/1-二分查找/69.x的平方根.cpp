#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid = 0;
        int ans = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s1;
	int x = 8;

	int ans = s1.mySqrt(x);
    std::cout << ans << std::endl;
    return 0;
}