#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* pre = head;
        while(--n) {
            p2 = p2->next;
        }
        while (p2 != nullptr && p2->next != nullptr) {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1==head) {
            head = p1->next;
        }else {
            pre->next = p1->next;
        }
        // delete(p1);

        return p1 == head ? nullptr : head;
    }
};

int main() {
    ListNode *head; 
    ListNode *p;
    ListNode *pre;
    head = new(ListNode); head->val = 1; pre = head;
    p = new(ListNode); p->val = 2; pre->next = p; pre = p;
    // p = new(ListNode); p->val = 3; pre->next = p; pre = p;
    // p = new(ListNode); p->val = 4; pre->next = p; pre = p;
    // p = new(ListNode); p->val = 5; pre->next = p; pre = p;

    Solution s1;
    ListNode* new_head = s1.removeNthFromEnd(head, 2);
    p = new_head;
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}