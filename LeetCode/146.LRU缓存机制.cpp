//least recently used
#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;

struct DuListNode
{
	int key;
	int value;
	DuListNode* pre;
	DuListNode* next;
	DuListNode() :pre(nullptr), next(nullptr) {}
	DuListNode(int _key, int _value)
		:key(_key), value(_value), pre(nullptr), next(nullptr)
	{}
};

class LRUCache
{
public:
	LRUCache(int ca) :size(0), capacity(ca)
	{
		head = BuyNode();
		tail = BuyNode();
		head->next = tail;
		tail->pre = head;
	}
	~LRUCache()
	{
		while (head->next != tail)
		{
			DeleteTail();
		}
		delete head;
		delete tail;
	}

	int Get(int _key)
	{
		if (cache.count(_key) == 0) return -1;
		DuListNode* p = cache[_key];
		p->next->pre = p->pre;
		p->pre->next = p->next;
		AddHead(p);
		return p->value;
	}
	void Put(int _key, int _value)
	{
		if (cache.count(_key) == 0)
		{
			if (size == capacity)
			{
				DeleteTail();
			}
			DuListNode* newNode = BuyNode();
			newNode->key = _key;
			newNode->value = _value;
			AddHead(newNode);
			cache[_key] = newNode;
			size++;
		}
		else
		{
			DuListNode* p = cache[_key];
			p->next->pre = p->pre;
			p->pre->next = p->next;
			p->value = _value;
			AddHead(p);
		}
	}
private:
	DuListNode* BuyNode()
	{
		DuListNode* newNode = new DuListNode();
		memset(newNode, 0, sizeof(DuListNode));
		return newNode;
	}
	void AddHead(DuListNode* p)
	{
		p->next = head->next;
		p->pre = head;
		head->next = p;
		p->next->pre = p;
	}
	void DeleteTail()
	{
		DuListNode* p = tail->pre;
		cache.erase(p->key);
		p->pre->next = tail;
		tail->pre = p->pre;
		delete p;
		--size;
	}
private:
	unordered_map<int, DuListNode*> cache;
	DuListNode* head;
	DuListNode* tail;
	int size;
	int capacity;
};

int main()
{
	LRUCache lru(1);
	lru.Put(2, 1);
	int x = lru.Get(1);
	cout << x << endl;

	return 0;
}