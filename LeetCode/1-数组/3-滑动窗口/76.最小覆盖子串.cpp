#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using std::unordered_map;
using std::string;

//暴力
class Solution {
public:
    string minWindow(string s, string t) {
        string res = s+t;
        unordered_map<char, int> tMap;
        for (char s : t) {
            if (tMap.count(s) > 0) {
                tMap[s]++;
            } else {
                tMap[s] = 1;
            }
        }
        
        unordered_map<char, int> tMapTmp = tMap;
        int i = 0, j = 0;
        for (; j < s.size(); j++) {
            if (tMap.count(s[i])<=0) {
                i++;
                continue;
            }
            if (tMap.count(s[j])>0 && tMapTmp.count(s[j])>0) {
                tMapTmp[s[j]]--;
                if (tMapTmp[s[j]] == 0) {
                    tMapTmp.erase(s[j]);
                }
                if (tMapTmp.empty()) {
                    if (res.size()>j-i+1) {
                        res = s.substr(i, j-i+1);
                    }
                    tMapTmp=tMap;
                    j=i;
                    i++;
                }
            }
        }
        if (res == s+t) {
            return "";
        }
        return res;
    }
};

class Solution2 {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

class Solution3 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        for (char s : t) {
            tMap[s]++;
        }

        unordered_map<char, int> tMapTmp;
        int i = 0, j = -1, len = s.size();
        int resLen = INT_MAX, startI = -1;
        while (j < len) {
            if (tMap.count(s[++j]) > 0) {
                tMapTmp[s[j]]++;
            }
            while (equal(tMap, tMapTmp) && i <= j) {
                if (resLen > j - i + 1) {
                    startI = i;
                    resLen = j - i + 1;
                }
                if (tMapTmp.count(s[i]) > 0) {
                    tMapTmp[s[i]]--;
                }
                i++;
            }
        }
        return startI == -1 ? "" : s.substr(startI, resLen);
    }
    bool equal(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for (const auto& pair : a) {
            if (b[pair.first] < pair.second) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution3 s1;

    string ans = s1.minWindow("ADOBECODEBANC", "ABC");
    std::cout << ans << std::endl;
    
    return 0;
}