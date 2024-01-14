#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int i=0; i<nums1.size(); i++) {
            m1[nums1[i]]++;
        }
        for (int i=0; i<nums2.size(); i++) {
            m2[nums2[i]]++;
        }
        unordered_map<int, int> mtmp=m1;
        if (m1.size() < m2.size()) {
            m1 = m2;
            m2 = mtmp;
        }
        for (unordered_map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
            if (m2.count(it->first) > 0) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}