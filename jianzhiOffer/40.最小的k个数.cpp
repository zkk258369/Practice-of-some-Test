#include<iostream>
#include<queue>
#include<time.h>
using namespace std;

class Solution // topk
{
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		vector<int> res(k);
        if(arr.empty() || k<1) return res;
		priority_queue<int> pque;
		int len = arr.size();
		for (int i = 0; i < k; i++)
		{
			pque.push(arr[i]);
		}
		for (int i = k; i < len; i++)
		{
			if (pque.top() > arr[i])
			{
				pque.pop();
				pque.push(arr[i]);
			}
		}
		for (int i = 0; !pque.empty(); i++)
		{
			res[i] = pque.top();
			pque.pop();
		}
		
		return res;
	}
};


class Solution  // quicksort
{
public:
	int partition(vector<int>& arr, int l, int r)
	{
		int pivot = arr[r];
		int i = l-1;
		for(int j=0; j<r; j++)
		{
			if(arr[j] < pivot)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i+1], arr[r]);
		return i+1;
	}
	int randomized_partition(vector<int>& arr, int l, int r)
	{
		int i = rand() % (r-l+1) + l;
		swap(arr[r], arr[i]);
		return partition(arr, l, r);
	}
	void randomized_select(vector<int>& arr, int l, int r, int k)
	{
		if(l >= r) return;
		int pos = randomized_partition(arr, l, r);
		int num = pos - l + 1;
		if(k == num) return;
		else if(k < num) randomized_select(arr, 0, pos-1, k);
		else randomized_select(arr, pos+1, r, k-num);
	}
	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		srand((unsigned)time(nullptr));
		randomized_select(arr, 0, arr.size()-1, k);
		vector<int> res(k);
		for(int i=0; i<k; i++)
		{
			res[i] = arr[i];
		}
		return res;
	}
};

int main()
{
	int ar[] = { 0, 0, 0, 2, 0, 5, 0 };
	int len = sizeof(ar) / sizeof(ar[0]);
	vector<int> arr(ar, ar + len);
	Solution s;
	vector<int> res = s.getLeastNumbers(arr, 4);
	for (auto i : res)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}