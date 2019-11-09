#include<iostream>


int FindValues(int* arr, int len, int val)//while
{
	int pos = -1;
	if (NULL == arr || len < 1)//
		return pos;
	int right = len - 1;
	int left = 0;
	while (left <= right)
	{
		//int mid = (right + left) / 2;//r + l 没有处理溢出 
		int mid = (right - left + 1) / 2 + left;
		if (arr[mid] > val)
			right = mid - 1;
		else if (arr[mid] < val)
			left = mid + 1;
		else
		{
			while(mid > left && arr[mid] == arr[mid - 1])
			{
				mid--;
			}
			pos = mid;
			break;
		}
	}
	return pos;
}

int search(int* arr, int left, int right, int val)
{
	int pos = -1;
	if (left <= right)
	{
		int mid = (right - left - 1) / 2 + left;
		if (arr[mid] > val)
		{
			pos = search(arr,left , mid - 1, val);
		}
		else if (arr[mid] < val)
		{
			pos = search(arr, mid + 1,right , val);
		}
		else
		{
			while (mid > left && arr[mid] == arr[mid - 1])--mid;
			pos = mid;
		}
	}
	return pos;
}

int SearchValues(int* arr, int len, int val)//digui
{
	if (NULL == arr || len < 1)//
		return -1;
	return search(arr, 0, len - 1, val); 
}

int main()
{
	int arr[] = { 12, 12, 12, 12, 23, 34, 34, 45, 45, 45, 45, 56, 67, 78, 89, 90, 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int val;
	std::cin >> val;
	int pos = SearchValues(arr, len, val);
	std::cout << "pos = " << pos << std::endl;

	return 0;
}