#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mapp;
        int head = 0, tail = 0, res = 0;
        while(tail < s.size())
        {
            if(mapp.count(s[tail]) > 0) head = max(head, mapp[s[tail]]+1);
            mapp[s[tail]] = tail;
            tail++;
            res = max(res, tail-head);
        }
        return res;
    }
};