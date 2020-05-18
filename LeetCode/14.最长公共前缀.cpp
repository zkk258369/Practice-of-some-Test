#include<bits/stdc++.h>
using namespace std;

//Longest Common Prefix(LCP)


/*
 * Solution1 水平扫描
 * LCP(S1 ... S2) = LCP(LCP(LCP(S1, S2), S3), ...Sn)    
 * 
*/
class Solution1
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0) return "";
        string pre = strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            for(int j=0; j<pre.size(); j++)
            {
                if(j >= strs[i].size() || pre[j] != strs[i][j])
                {
                    pre.erase(j, pre.size()-j);
                    break;
                }
                if(pre.empty()) return "";
            }
        }
        return pre;
    }
};

class Solution2 //纵向扫描
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;
        if(strs.size() == 0) return res;
        for(int i=0; ; i++)
        {
            for(int j=0; j<strs.size(); j++)
            {
                if(i >= strs[j].size())
                {
                    if(j != 0) res.pop_back();
                    return res;
                }
                if(j == 0) res.push_back(strs[j][i]);
                if(strs[j][i] != res[i]) { res.pop_back(); return res; }
            }
        }
        return res;
    }
};