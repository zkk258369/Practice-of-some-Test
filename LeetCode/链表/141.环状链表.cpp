#include<bits/stdc++.h>

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

/*
 * 这个解法时间复杂度为o(n)，n为链表节点总个数
 * 空间复杂度为o(1)
 * 采用快慢指针，在环状链表中快指针会追上慢指针的原理，解决此题
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(nullptr == head || nullptr == head->next) return false;

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast != slow)
        {
            if(nullptr == fast || nullptr == fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};