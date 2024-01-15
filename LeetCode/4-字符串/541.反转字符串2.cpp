#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k) {
            std::reverse(s.begin() + i, s.begin() + std::min(i + k, n));
        }
        return s;
    }
};

int main() {
    
    return 0;
}