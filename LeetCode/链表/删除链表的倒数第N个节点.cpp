#include<bits/stdc++.h>

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

/*
 * 扫描一次
 * 设置两个指针，p1，p2
 * p1先走n+1步，之后p1，p2一起向后，直到p1等于null
 * 删除p2的后一节点
*/
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(nullptr == head) return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p1 != nullptr)
        {
            if(n<0) p2 = p2->next;
            n--;
            p1 = p1->next;
        }
        if(n == 0) return head->next;
        p2->next = p2->next->next;
        return head;
    }
};