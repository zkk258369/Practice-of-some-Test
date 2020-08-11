#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution // 暴力法 超时
{
public:
	string shortestPalindrome(string str)
	{
		int len = str.size();
		for (int i = 0; i<len; i++)
		{
			string strtmp(str, 0, len - i);
			if (IsPalindrome(strtmp))
			{
				string rstr(str.begin() + len - i, str.end());
				std::reverse(rstr.begin(), rstr.end());
				rstr += str;
				return rstr;
			}
		}
		string rstr(str.rbegin(), str.rend());
		rstr += str;
		return rstr;
	}
	bool IsPalindrome(string& str)
	{
		int i = 0;
		int j = str.size() - 1;
		while (i <= j)
		{
			if (str[i] != str[j]) return false;
			i++; j--;
		}
		return true;
	}
};

class Solution // 暴力法 超时
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.substr(0, n - i) == rev.substr(i))
            {
                return rev.substr(0, i) + s;
            }
        }
        return "";
    }
};

class Solution // 双指针+递归
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == s[j]) i++;
        }
        if (i == n) return s;
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

class Solution  // KMP 找最长匹配的前缀后缀
{
public:
	string shortestPalindrome(string s)
	{
		int n = s.size();
		string rev(s.rbegin(), s.rend());
		int len = Next(string(s + "#" + rev));
		return rev.substr(0, n - len) + s;
	}
	int Next(const string& sub)
	{
		int sublen = sub.size();
		vector<int> next(sublen + 1);
		next[0] = -1;
		int j = 1;
		int k = 0;
		while (j < sublen)
		{
			if (k == -1 || sub[k] == sub[j])
			{
				next[++j] = ++k;
			}
			else k = next[k];
		}
		return next[sublen];
	}
};

int main()
{
	Solution s;
	string str("aabba");
	string res = s.shortestPalindrome(str);
    cout << res << endl;

	return 0;
}
