//从尾到头打印链表
#if 1
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>

using std::vector;
using std::iterator;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	vector<int> printListFromTailToHead(ListNode* head)
	{
		if (head == NULL)
		{
			return vector<int>();
		}
		else
		{
			vector<int> ArrayList(0);
			for (ListNode* p = head; p != NULL; p = p->next)
			{
				ArrayList.push_back(p->val);
			}
			vector<int>::iterator first = ArrayList.begin();
			vector<int>::iterator last = ArrayList.end();
			reverse(first, last);
			copy(first, last, std::ostream_iterator<int>(std::cout, " "));

			return ArrayList;
		}//end else

		//std::vector<int> vec;
		//std::stack<int> nodes;
		//ListNode* pNode = head;
		//if (head == nullptr)
		//{
		//	return vec;
		//}
		//while (pNode != nullptr)
		//{
		//	nodes.push(pNode->val);
		//	pNode = pNode->next;
		//}
		//while (!nodes.empty())
		//{
		//	vec.push_back(nodes.top());
		//		nodes.pop();
		//}
		//return vec;

	}//end printListFromTailToHead
};


int main()
{
	//逆置链表
	struct ListNode L1(67);
	struct ListNode L2(0);
	L1.next = &L2;
	struct ListNode L3(24);
	L2.next = &L3;
	struct ListNode L4(58);
	L3.next = &L4;

	Solution s1;
	s1.printListFromTailToHead(&L1);

	return 0;
}
#endif