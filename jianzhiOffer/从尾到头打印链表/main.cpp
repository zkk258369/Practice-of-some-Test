/*
��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
���˼·��
Ҫ�����Ƿ���ԸĶ�ԭ��������
1.���������ã���Ϊ������ָ��ȫ�����ã�Ȼ���ӡ�������ԸĶ�����
2.�ȱ������ĺ��ӡ����������Ŀ����ȴ�ӡ�������ú���ȳ���ջ��ʵ�֡�
3.�ݹ�ʵ�֡�
*/
//��β��ͷ��ӡ����
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
		//��reverse()����vector����
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

		//��stackʵ��
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

		//�Ķ�ԭ������
		//if(head == NULL)
		//{
		//	return vector<int>();
		//}
		//else
		//{
		//	ListNode* ptmp = head;   //ָ����һ���ڵ�
		//	ListNode* pnext = NULL;  //ָ����һ���ڵ�
		//	ListNode* p = head->next;//ָ��ǰ�ڵ�
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

//�ݹ�ʵ��
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
	//��������
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