#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution  //non recrusive
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(nullptr == head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* pcur = head;
        ListNode* pnext = nullptr;
        while(pcur != nullptr)
        {
            pnext = pcur->next;
            pcur->next = pre;
            pre = pcur;
            pcur = pnext;
        }
        return pre;
    }
};

class Solution2  //non recrusive 漂亮
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = nullptr;
        ListNode* cur = head;
        for(; cur != nullptr; swap(cur, p))
        {
            swap(p, cur->next);
        }
        return p;
    }
};

class Solution  //recrusive
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next) return head;

        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};