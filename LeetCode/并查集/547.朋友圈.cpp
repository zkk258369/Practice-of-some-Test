#include<iostream>
#include<vector>
using namespace std;

class UFSets
{          
public:
	UFSets(int s)
	{
		size = s;
		parent = new int[size + 1];
		for (int i = 0; i <= size; i++) parent[i] = -1;
	}
	~UFSets() { delete[] parent; }

	const UFSets& operator=(UFSets const& Value);

	void Union(int Root1, int Root2)
	{
		int r1 = Find(Root1);
		int r2 = Find(Root2);
		if (r1 != r2)
		{
			int temp = parent[r1] + parent[r2];
			if (parent[r2] < parent[r1])
			{
				parent[r1] = r2;      //Root2中结点数多
				parent[r2] = temp;    //Root1指向Root2
			}
			else
			{
				parent[r2] = r1;     //Root1中结点数多
				parent[r1] = temp;   //Root2指向Root1
			}
		}
	}

	int Find(int x) //路径压缩
	{
		if (parent[x] < 0) return x;
		else
		{
			int res = Find(parent[x]);
			parent[x] = res;
			return res;
		}
	}

    int CountOfRoot()
    {
        int count = 0;
        for(int i=0; i<size; i++)
        {
            if(parent[i] < 0) count++;
        }
        return count;
    }
private:
	int *parent;
	int size;
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        int n = M.size();
        UFSets uf(n);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(M[i][j] == 1) uf.Union(i, j);
            }
        }
        return uf.CountOfRoot();
    }
};

int main()
{
	vector<vector<int>> vec1 = { { 1, 1, 0 },
								{ 1, 1, 0 },
								{ 0, 0, 1 } };
	vector<vector<int>> vec2 = { { 1, 1, 0 },
								{ 1, 1, 1 },
								{ 0, 1, 1 } };
	Solution s;
	int res = s.findCircleNum(vec2);
	cout << res << endl;

	return 0;
}