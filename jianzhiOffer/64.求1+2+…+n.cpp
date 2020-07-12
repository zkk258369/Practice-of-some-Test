#include<iostream>
using namespace std;

/*
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

// recursive
class Solution
{
public:
    int sumNums(int n)
    {
        n && (n += sumNums(n-1));
        return n;
    }
};

// 快速乘
// https://leetcode-cn.com/problems/qiu-12n-lcof/solution/qiu-12n-by-leetcode-solution/

// 用加法和位移实现两数相乘
int quickMulti(int A, int B)
{
    int ans = 0;
    for ( ; B; B >>= 1)
    {
        if (B & 1) ans += A;
        A <<= 1;
    }
    return ans;
}

class Solution2
{
public:
    int sumNums(int n)
    {
        int res = 0;
        int A = n;
        int B = n+1;

        (B & 1) && (res += A);//1
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//2
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//3
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//4
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//5
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//6
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//7
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//8
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//9
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//10
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//11
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//12
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//13
        A <<= 1;
        B >>= 1;

        (B & 1) && (res += A);//14
        A <<= 1;
        B >>= 1;
        return res >> 1;
    }
};