#include <iostream>
#include<vector>
#include<iomanip>

class Solution {
public:
	bool Find(int target, vector<vector<int> > array)
	{
		//定义最左上脚位置
		int arri = 0;
		int arrj = array[0].size() - 1;
		while (array[arri][arrj] != target)
		{
			if (arri == array.size() - 1 && arrj == 0)
			{
				return false;
			}
			if (array[arri][arrj] > target)
			{
				arrj--;
			}
			else
			{
				arri++;
			}
		}
		return true;
	}
};


int main()
{
	int target = 13;
	int m = 4;
	int n = 5;
	vector<vector<int> >array(m, vector<int>(n));//m行n列
	array[0][0] = 1; array[0][1] = 2; array[0][2] = 3; array[0][3] = 4; array[0][4] = 5;
	array[1][0] = 5; array[1][1] = 6; array[1][2] = 7; array[1][3] = 8; array[1][4] = 10;
	array[2][0] = 6; array[2][1] = 7; array[2][2] = 13; array[2][3] = 14; array[2][4] = 15;
	array[3][0] = 16; array[3][1] = 17; array[3][2] = 18; array[3][3] = 19; array[3][4] = 20;

	Solution test1;
	bool tf;
	
	tf = test1.Find(target, array);
	if (tf == true)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	return 0;
}
