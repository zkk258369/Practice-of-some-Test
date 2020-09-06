#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), cmp);
        
    }
};