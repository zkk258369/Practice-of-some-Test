#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

// kmp算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        int len1 = haystack.size();
        int len2 = needle.size();

        vector<int> next(len2);
        getNext(next, needle);

        for (int i = 0, j = -1; i < len1; i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j+1]) {
                j++;
            }
            if (j == len2 - 1) {
                return i - len2 + 1;
            }
        }
        return -1;
    }
    void getNext(vector<int>& next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {     // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j];                     // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
};

int main() {
    Solution s1;
    int index = s1.strStr("abababab", "abababab");
    std::cout << index << std::endl;
    
    return 0;
}