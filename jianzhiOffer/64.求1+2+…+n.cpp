#include<iostream>
using namespace std;

/*
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

class Solution
{
public:
    int sumNums(int n)
    {
        if(n == 1) return 1;
        else return sumNums(n-1) + n;
    }
};