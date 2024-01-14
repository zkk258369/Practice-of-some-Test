#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (int i=0; i<s.size(); i++) {
            m1[s[i]]++;
        }
        for (int i=0; i<t.size(); i++) {
            m2[t[i]]++;
        }

        if (m1.size() != m2.size()) {
            return false;
        }
        for (unordered_map<char, int>::iterator it=m1.begin(); it != m1.end(); it++) {
            if (m2[it->first] != it->second) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s1;
    bool res = s1.isAnagram("anagram", "nagaram");
    std::cout << res << std::endl;

    return 0;
}