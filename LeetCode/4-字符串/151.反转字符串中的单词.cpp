#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                continue;
            }
            int right = i;
            int left = i - 1;
            while (left >= 0 && s[left] != ' ') {
                left--;
            }
            left++;
            int index = left;
            int len = right - left + 1;
            res += s.substr(index, len);
            res += " ";
            i = left;
        }
        res.erase(res.size() - 1);
        return res;
    }
};

int main() {
    Solution s1;
    string res = s1.reverseWords("the sky is blue");
    std::cout << res << std::endl;
    
    return 0;
}