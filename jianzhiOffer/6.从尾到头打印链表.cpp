/*
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
解决思路：
要考虑是否可以改动原来的链表。
1.将链表逆置，即为将链表指针全部反置，然后打印。（可以改动链表）
2.先遍历到的后打印，后遍历到的可以先打印，可以用后进先出的栈来实现。
3.递归实现。
*/
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
		//用reverse()逆置vector数组
		//if(head == NULL)
		//{
		//	return vector<int>();
		//}	
		//else
		//{
		//	vector<int> ArrayList(0);
		//	for (ListNode* p = head; p != NULL; p = p->next)
		//	{
		//		ArrayList.push_back(p->val);
		//	}
		//	vector<int>::iterator first = ArrayList.begin();
		//	vector<int>::iterator last = ArrayList.end();
		//	reverse(first, last);
		//	copy(first, last, std::ostream_iterator<int>(std::cout, " "));

		//	return ArrayList;
		//}//end else

		//用stack实现
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

		//改动原来链表
		//if(head == NULL)
		//{
		//	return vector<int>();
		//}
		//else
		//{
		//	ListNode* ptmp = head;   //指向上一个节点
		//	ListNode* pnext = NULL;  //指向下一个节点
		//	ListNode* p = head->next;//指向当前节点
		//	while (p != NULL)
		//	{
		//		pnext = p->next;
		//		p->next = ptmp;
		//		ptmp = p;
		//		p = pnext;
		//	}
		//	head->next = NULL;
		//	ListNode* newhead = ptmp;
		//	vector<int> arr;
		//	while (ptmp != NULL)
		//	{
		//		arr.push_back(ptmp->val);
		//		ptmp = ptmp->next;
		//	}
		//	return arr;
		//}

	}//end printListFromTailToHead
};

//递归实现
void printReverseLinkList(ListNode* head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			printReverseLinkList(head->next);
		}
		std::cout << head->val << " ";
	}
}

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


	//Solution s1;
	//vector<int> arr = s1.printListFromTailToHead(&L1);
	printReverseLinkList(&L1);

	return 0;
}
#endif