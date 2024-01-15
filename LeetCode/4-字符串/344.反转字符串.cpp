#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        for (int i=0; i<len/2; i++) {
            std::swap(s[i], s[len-1-i]);
        }
    }
};

int main() {
    
    return 0;
}