#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, bool> m;
        vector<char> vec;
        for(char c : s)
        {
            if(m.find(c) == m.end())
            {
                vec.push_back(c);
                m[c] = true;
            }
            else m[c] = false;
        }
        for(auto it : vec)
        {
            if(m[it]) return it;
        }
        return ' ';
    }
};