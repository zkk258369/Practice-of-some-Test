#include<iostream>

using namespace std;

typedef struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

typedef struct message
{
	bool hasCycle;             //是否有环
	ListNode* equal;           //快指针追上慢指针的节点
	ListNode* IntoCycleNode;   //入环节点
	int L;                     //非环长度
	int R;                     //环长度
	message() :hasCycle(false), IntoCycleNode(nullptr), L(0), R(0) {}
}message;

void hasCycle(ListNode* head, message& m)
{
    if (nullptr == head || nullptr == head->next) return;

	ListNode* slow = head->next;
	ListNode* fast = head->next->next;
	while (fast != slow)
	{
		if (nullptr == fast || nullptr == fast->next) return;
		slow = slow->next;
		fast = fast->next->next;
	}
	m.hasCycle = true;
    m.equal = fast;
}

void getNodeIntoCycle(ListNode* head, message& m)
{
    ListNode* p1 = head;
	ListNode* p2 = m.equal;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	m.IntoCycleNode = p1;
}

void getL(ListNode* head, message& m)
{
    ListNode* p = head;
	int count = 0;
	while (p != m.IntoCycleNode)
	{
		p = p->next;
		++count;
	}
	m.L = count;
}

void getR(ListNode* head, message& m)
{
    int count = 1;
	ListNode* p = m.IntoCycleNode->next;
	while (p != m.IntoCycleNode)
	{
		p = p->next;
		++count;
	}
	m.R = count;
}

int main()
{
	ListNode head(0);
	ListNode* p = &head;
	ListNode* p6 = nullptr;
	for (int i = 0; i<10; ++i)
	{
		ListNode* tmp = new ListNode(i+1);
		if (i + 1 == 6) p6 = tmp;
		p->next = tmp;
		p = tmp;
	}
	p->next = p6;

	message m;
	hasCycle(&head, m);
	getNodeIntoCycle(&head, m);
	getL(&head, m);
	getR(&head, m);
	cout << "是否有环：" << (m.hasCycle==true ? "是" : "否") << endl;
	cout << "入环节点：val = " << m.IntoCycleNode->val << endl;
	cout << "非环长度X：" << m.L << endl;
	cout << "环长度R：" << m.R << endl;

	//for (ListNode* q = &head; q != nullptr; q = q->next)
	//{
	//	cout << q->val << " ";
	//}
	//cout << endl;

	system("pause");
	return 0;
}