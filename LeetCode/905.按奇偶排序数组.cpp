#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		int len = A.size();
		int i = 0;
		int j = len - 1;
		while (i<j)
		{
			while (i < len && A[i] % 2 == 0) i++;
			while (j >= 0 && A[j] % 2 == 1) j--;
			if(i<j)
			{
				A[i] ^= A[j];
				A[j] ^= A[i];
				A[i] ^= A[j];
				i++;
				j--;
			}
		}
		return A;
	}
};

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& vec)
	{
        sort(vec.begin(), vec.end(), [](int a, int b){ return (a % 2) < (b % 2); });
		return vec;
	}
};

int main()
{
	vector<int> vec = { 3,1,4,2};
	Solution s;
	s.sortArrayByParity(vec);
	for (auto i : vec) cout << i << " ";
	return 0;
}