//2.两数相加
/*
给出两个 非空 的链表用来表示两个非负的整数。
其中，它们各自的位数是按照 逆序 的方式存储的，
并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include<iostream>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		struct ListNode *pl1 = l1, *pl2 = l2,*pans,*pit;
		pans = pit = NULL;
		int c = 0;//进位
		for (; pl1 != NULL && pl2 != NULL; pl1 = pl1->next, pl2 = pl2->next)
		{
			int value = (pl1->val + pl2->val + c) % 10 ;
			int ca = c;
			c = 0;
			struct ListNode *newNode = new ListNode(value);
			if (((pl1->val + pl2->val + ca) / 10) == 1)
			{
				c = 1;
			}
			if (pans == NULL)
			{
				pans = newNode;
				pit = pans;
			}
			else
			{
				pit->next = newNode;
				pit = pit->next;
			}

		}
		struct ListNode *p = NULL;
		if (pl1 != NULL || pl2 != NULL)
		{
			if (pl1 != NULL)
				p = pl1;
			else
				p = pl2;
		}
		if (pl1 == NULL && pl2 == NULL && c != 0)
		{
			struct ListNode *newNode = new ListNode(c);
			c = 0;
			pit->next = newNode;
			pit = pit->next;
		}
		for (; p != NULL || c != 0; )
		{
			if (p != NULL)
			{
				int value = (p->val + c) % 10;
				struct ListNode *newNode = new ListNode(value);
				int ca = c;
				c = 0;
				if (((p->val + ca) / 10) == 1)
				{
					c = 1;
				}
				pit->next = newNode;
				pit = pit->next;
				p = p->next;
			}
			else
			{
				struct ListNode *newNode = new ListNode(c);
				c = 0;
				pit->next = newNode;
				pit = pit->next;
			}
		}
		return pans;
	}
};

int main()
{
	struct ListNode L1(3);
	struct ListNode *p1 = &L1;
	struct ListNode L2(7);
	L1.next = &L2;
	//struct ListNode L3(3);
	//L2.next = &L3;
	//struct ListNode L7(8);
	//L3.next = &L7;
	//struct ListNode L8(9);
	//L7.next = &L8;

	struct ListNode L4(9);
	struct ListNode *p2 = &L4;
	struct ListNode L5(2);
	L4.next = &L5;
	//struct ListNode L6(4);
	//L5.next = &L6;
	//struct ListNode L9(3);
	//L6.next = &L9;

	Solution s1;
	struct ListNode *pans = s1.addTwoNumbers(p1,p2);
	for (; pans != NULL; pans = pans->next)
	{
		std::cout << pans->val << " ";
	}
	std::cout << std::endl;
	system("pause");

	return 0;
}