#include<bits/stdc++.h>

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

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