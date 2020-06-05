
//从尾到头打印链表
#if 1
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution1  // 递归
{
public:
    vector<int> reversePrint(ListNode* head)
	{
        if(!head) return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};

class Solution2  // reverse反转
{
public:
    vector<int> reversePrint(ListNode* head)
	{
        vector<int> res;
        if(head == nullptr) return res;
        for(ListNode* p=head; p != nullptr;p=p->next)
        {
            res.push_back(p->val);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution3  // 改变链表结构
{
public:
    vector<int> reversePrint(ListNode* head)
	{
        vector<int> res;
        if(head == nullptr) return res;
        ListNode* pre = nullptr;
		ListNode* p = head;
		ListNode* next = nullptr;
		while(p != nullptr)
		{
			next = p->next;
			p->next = pre;
			pre = p;
			p = next;
		}
		head = pre;
		for(p=head; p != nullptr;p=p->next)
        {
            res.push_back(p->val);
        }
        return res;
    }
};
#endif