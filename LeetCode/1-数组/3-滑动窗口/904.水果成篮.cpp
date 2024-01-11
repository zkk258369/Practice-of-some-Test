#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;
using std::max;

// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int n = fruits.size();
        int i = 0;
        int j = 0;
        vector<pair<int, int>> sum(2, pair<int, int>(-1, 0));
        for (; i < n && j < n;) {
            if (sum[0].first == -1 || sum[1].first == -1 ||
                fruits[j] == sum[0].first || fruits[j] == sum[1].first) {
                if (sum[0].first == -1) {
                    sum[0].first = fruits[j];
                }else {
                    if (sum[0].first != fruits[j] && sum[1].first == -1) {
                        sum[1].first = fruits[j];
                    }
                }
                if (fruits[j] == sum[0].first) {
                    sum[0].second = sum[0].second + 1;
                } else {
                    sum[1].second = sum[1].second + 1;
                }
                res = max(res, sum[0].second + sum[1].second);
                j++;
            } else {
                if (fruits[i] == sum[0].first) {
                    sum[0].second = sum[0].second - 1;
                    if (sum[0].second == 0) {
                        sum[0].first = -1;
                    }
                    i++;
                    continue;
                }
                if (fruits[i] == sum[1].first) {
                    sum[1].second = sum[1].second - 1;
                    if (sum[1].second == 0) {
                        sum[1].first = -1;
                    }
                    i++;
                    continue;
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int n = fruits.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> cnt;
        for (; j < n;++j) {
            ++cnt[fruits[j]];
            while(cnt.size()>2){
                auto it = cnt.find(fruits[i]);
                --it->second;
                if (it->second==0){
                    cnt.erase(it);
                }
                ++i;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};

int main()
{
    Solution s1;
    int num[] = {3,3,3,1,2,1,1,2,3,3,4};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    int ans = s1.totalFruit(nums);
    std::cout << ans << std::endl;
    return 0;
}