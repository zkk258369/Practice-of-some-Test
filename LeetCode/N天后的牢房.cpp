#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        unordered_map<int,int> m;
        int s = State(cells);
        m[s] = 0;
        while(N>0)
        {
            --N;
            NextDay(cells);
            s = State(cells);
            if(m.count(s))
            {
                break;
            }
            else
            {
                int size = m.size();
                m[s] = size;
            }
        }
        int loop = m.size() - m[s];
        N %= loop;
        while(N>0)
        {
            NextDay(cells);
            --N;
        }
        return cells;
    }
    int State(vector<int>& cells)
    {
        int state = 0;
        for(unsigned int i=0; i<cells.size(); ++i)
        {
            state += (cells[i]<<i);
        }
        return state; 
    }
    void NextDay(vector<int>& cells)
    {
        for(unsigned int i=1; i<cells.size()-1; ++i)
        {
            cells[i] |=  ( 1 - ((cells[i-1]&1)^(cells[i+1]&1)) )<<1;
        }
        cells[0] = 0;
        cells[7] = 0;
        for(unsigned int i=1; i<cells.size(); ++i)
        {
            cells[i] >>= 1;
        }
    }
};

int main()
{
    int arr[] = {0,1,0,1,1,0,0,1};//state = 2+8+16+128=154
    vector<int> vec(arr, arr+8);
    Solution s1;
    int N = 7;
    vector<int> res = s1.prisonAfterNDays(vec, N);
    cout << "day" << N << ":";
    for(auto it : res)
    {
        cout << it << ",";
    }
    cout<<endl;
    
    system("pause");
    return 0;
}

/*
8 间牢房排成一排，每间牢房不是有人住就是空着。

每天，无论牢房是被占用或空置，都会根据以下规则进行更改：

如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
否则，它就会被空置。
（请注意，由于监狱中的牢房排成一行，所以行中的第一个和最后一个房间无法有两个相邻的房间。）

我们用以下方式描述监狱的当前状态：如果第 i 间牢房被占用，则 cell[i]==1，否则 cell[i]==0。

根据监狱的初始状态，在 N 天后返回监狱的状况（和上述 N 种变化）。

 

示例 1：

输入：cells = [0,1,0,1,1,0,0,1], N = 7
输出：[0,0,1,1,0,0,0,0]
解释：
下表概述了监狱每天的状况：
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

0,1,0,1,1,0,0,1,   0
0,1,1,0,0,0,0,0,   1
0,0,0,0,1,1,1,0,   2
0,1,1,0,0,1,0,0,   3
0,0,0,0,0,1,0,0,   4
0,1,1,1,0,1,0,0,   5
0,0,1,0,1,1,0,0,   6
0,0,1,1,0,0,0,0,   7
0,0,0,0,0,1,1,0,   8
0,1,1,1,0,0,0,0,   9
0,0,1,0,0,1,1,0,   10
0,0,1,0,0,0,0,0,   11
0,0,1,0,1,1,1,0,   12
0,0,1,1,0,1,0,0,   13
0,0,0,0,1,1,0,0,   14
0,1,1,0,0,0,0,0,   1

示例 2：

输入：cells = [1,0,0,1,0,0,1,0], N = 1000000000
输出：[0,0,1,1,1,1,1,0]
 

提示：

cells.length == 8
cells[i] 的值为 0 或 1 
1 <= N <= 10^9
*/