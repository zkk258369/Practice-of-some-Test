#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        int skipS=0, skipT = 0;
        while (i>=0 || j>=0) {
            while (i>=0) {
                if (s[i] == '#') {
                    skipS++, i--;
                }else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j>=0) {
                if (t[j] == '#') {
                    skipT++, j--;
                }else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i>=0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--,j--;
        }
        return true;
    }
};

int main()
{
    Solution s1;
    string s = "xywrrmp";
    string t = "xywrrmu#p";

	bool ans = s1.backspaceCompare(s, t);

    std::cout << ans << std::endl;
    return 0;
}