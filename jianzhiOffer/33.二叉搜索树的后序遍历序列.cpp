#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    bool judge(vector<int>& vec, int l, int r)
    {
        if(l >= r)
            return true;
        int i = l;
        while(vec[i]<vec[r] && i<r)
            ++i;
        for(int j=i+1; j<r; ++j)
        {
            if(vec[j] < vec[r])
                return false;
        }
        return judge(vec, l, i-1) && judge(vec, i, r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        bool res = false;
        if(sequence.empty())
            return res;
        res = judge(sequence, 0, sequence.size()-1);
        return res;
    }
};