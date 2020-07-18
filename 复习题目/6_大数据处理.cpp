/*
 * 问题一：我的分析和设计，以及类型设计
 * 1. 生成一个有1000万整数的数组文件
 * 2. 按照一致性哈希将1000万数据分成100份
 * 3. 分别对每个文件进行hash统计，并且将hash表中的数据放到最小堆中，保持堆的大小为1000
 * 4. 统计完所有文件时，将top1000的数据存放到文件中
*/

/*
top 50

*/

/*
 * 问题二：代码实现
*/

/*
 * 问题三：hash_map 与 map 的区别
 * c++ 标准库的std::map内部是排序的，内部使用的是红黑树实现，不管是增加还是查找的时间复杂度 O(logN)。
 * 而c++ 标准库的hashmap其实叫作std::unordered_map，其增加和查询的时间复杂度才是 O(1)。它提供了类似map的方法。
*/

/*
 * 问题四：hash_set, hash_map, map 的应用场景
 * hash_set的键就是值，适合数据不能重复的场景，且不需要map的能力。
 * hash_map也适合数据不能重复的场景，但其有map能力，适合于key-value形式的查找。
 * map相比于hash_map，其底层是红黑树实现，是有序的，而hash_map不是有序存储的。map的查询效率是O(logN)，低于hash_map的查询效率，适合于我们需要有序的key-value查询。
*/

/*
 * 问题五：它们线程安全吗？ 你如何解决
 * c++STL中hash_set, hash_map, map都是线程不安全的，我们在操作时可以增加锁，确保线程安全。
*/

/*
 * 问题六：你的代码中使用了STL 里的priority_queue，讲解priority_queue的特点
 * 优先级队列用了最大堆的方式实现，其实际存储是在一个数组中。每次在push数据或者pop数据时都会调整堆。push数据时，将数据放到最后，与它的父亲比较，如果比父亲大则与父亲交换数据，一直循环，直到比父亲小。pop数据时，将数组最后的数据放到最前面，然后与最大子节点比较，如果比子节点小则交换数据，一直循环，直到比子节点大为止。
*/

/*
 * 问题七：你编程实现堆的调整函数
 * 实现最大堆的调整
*/
// push时，向上调整
void AdjustUp(int* arr, int cursize)
{
	int son = cursize - 1;
	int parent = (son - 1) / 2;
	while(son > 0)
	{
		if(arr[son] > arr[parent])
		{
			swap(arr[son], arr[parent]);
		}
		else break;
		son = parent;
		parent = (son - 1) / 2;
	}
}

// pop时，向下调整
void AdjustDown(int* arr, int cursize)
{
	int parent = 0;
	int son = parent * 2 + 1;
	while(son <= cursize - 1)
	{
		if(son + 1 < cursize - 1)
		{
			son = arr[son] > arr[son+1] ? son : son + 1;
		}
		if(arr[son] < arr[parent]) break;
		swap(arr[son], arr[parent]);
		parent = son;
		son = parent * 2 + 1;
	}
}


// 找到重复top 1000  在文件中操作
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include <algorithm>
#include<unordered_map>
#include<time.h>
#include<limits.h>
using namespace std;

typedef struct Node
{
	int x;
	int y;
	Node(int a = 0, int b = 0) :x(a), y(b) {}
	friend bool operator<(const Node& a, const Node& b);
}Node;

inline bool operator<(const Node &a, const Node &b)
{
	return a.y > b.y;
}


class Topk
{
public:
	Topk(int _k) :k(_k) {}

	void insert(const Node& value)
	{
		if (pque.size() < k)
		{
			pque.push(value);
		}
		else if (value.y > pque.top().y)
		{
			pque.pop();
			pque.push(value);
		}
	}

	void print(vector<Node>& vec)
	{
		while (!pque.empty())
		{
			vec[pque.size() - 1] = pque.top();
			pque.pop();
		}
	}
private:
	int k;
	// 最小堆
	priority_queue<Node> pque;
};

void Create1000w(int number_count)
{
	clock_t start_time = clock();
	srand(unsigned(time(0)));
	int max = 1047483648;
	int min = -1047483648;
	FILE* file = freopen("data1000w.txt", "w", stdout);
	if (nullptr == file)
	{
		fprintf(stdout, "open file error");
	}
	else
	{
		for (int i = 0; i < number_count; i++)
		{
			int tmp = rand() + min;
			cout << tmp << " ";
		}
	}
	fclose(file);
	freopen("CON", "w", stdout);

	cout << "elapsed time:" << double(clock() - start_time) / CLOCKS_PER_SEC << 's' << endl;
}

void Divide()
{
	char pathi[20] = "data1000w.txt";
	fstream ifile(pathi, ios::in);
	while (!ifile.eof())
	{
		int num;
		ifile >> num;
		int index = abs(num % 100);
		char patho[200] = { 0 };
		sprintf(patho, "disdata/%d.txt", index);
		fstream ofile(patho, ios_base::out | ios_base::app);
		ofile << num << " ";
		ofile.close();
	}
	ifile.close();
}

int main()
{
	int number_count = 10000000;
	int k = 1000;
	vector<Node> result;
	result.resize(1000);




	// 创建1000w数据
	//Create1000w(number_count);

	// 将1000w数据划分在100个文件中
	//Divide();

	// 利用map对小文件中的数据进行统计,并将数据放入topk中
	// 数据-个数
	//map<int, int> map;


	clock_t start_time = clock();

	Topk topk(k);
	int i = 0;
	int tmp;
	while (i < 100)
	{
		unordered_map<int, int> map;
		char path[200] = { 0 };
		sprintf(path, "disdata/%d.txt", i);
		fstream ifile(path, ios_base::in);
		while (!ifile.eof())
		{
			ifile >> tmp;
			if (map.count(tmp) > 0)
			{
				map[tmp] += 1;
			}
			else
			{
				map[tmp] = 1;
			}
		}
		ifile.close();
		unordered_map<int, int>::iterator it = map.begin();
		for (; it != map.end(); it++)
		{
			topk.insert(Node(it->first, it->second));
		}
		i++;
	}

	topk.print(result);
	char resultpath[200] = "result.txt";
	fstream ofile(resultpath, ios_base::out);
	i = 0;
	ofile << "Rank \t number \t count" << endl;
	while (i < k)
	{
		ofile << i << "\t" << result[i].x << "\t" << result[i].y << endl;
		i++;
	}
	ofile.close();

	cout << "elapsed time:" << double(clock() - start_time) / CLOCKS_PER_SEC << 's' << endl;

	return 0;
}


// 直接创建1000w整形数组
#if 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<time.h>
#include<hash_map>
#include<queue>
#include<iostream>
using namespace std;

const int ArSize = 100000;

struct IntPair_map
{
	int data;
	int ref;
	operator int() const  // 比较时用data比较即可
	{
		return data;
	}
};

struct IntPair_pri
{
	int data;
	int ref;
	operator int() const  // 比较时用ref比较即可
	{
		return ref;
	}
};

void Print_Array(IntPair_pri *br, int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << i << "\t" << br[i].data << "\t" << br[i].ref << endl;
	}
	cout << endl;
}

int* Init_Array(unsigned int size)
{
	int * p = (int*)malloc(sizeof(int)*size);
	if (NULL == p) exit(EXIT_FAILURE);
	for (int i = 0; i<size; ++i)
	{
		p[i] = rand();
	}
	return p;
}

int main()
{
	clock_t start_time = clock();

	int* ar = NULL;
	const int n = ArSize;
	ar = Init_Array(n);
	IntPair_pri br[1000];

	hash_map<int, IntPair_map> my_hmap;
	my_hmap.reserve(n);
	priority_queue<IntPair_pri, vector<IntPair_pri> > pri_qu;

	for (int i = 0; i<n; ++i)
	{
		IntPair_map x = { ar[i], 1 };
		//auto & a = my_hmap[ar[i]] = x;
		//a.ref += 1;
		if (my_hmap.count(ar[i]))
		{
			my_hmap[ar[i]].ref += 1;
		}
		else my_hmap[ar[i]] = x;
	}

	for (auto &x : my_hmap)
	{
		IntPair_pri a = { x.second.data, x.second.ref };
		pri_qu.push(a);
	}

	for (int i = 0; i<1000 && !pri_qu.empty(); ++i)
	{
		br[i] = pri_qu.top(); pri_qu.pop();
	}
	Print_Array(br, 1000);

	cout << "elapsed time:" << double(clock() - start_time) / CLOCKS_PER_SEC << 's' << endl;

	return 0;
}
#endif
