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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = 0, len2 = 0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != nullptr) {
            p1 = p1->next;
            len1++;
        }
        while (p2 != nullptr) {
            p2 = p2->next;
            len2++;
        }
        if (len1 > len2) {
            p1 = headA; p2 = headB;
            int n = len1 - len2;
            while (n--) {
                p1 = p1->next;
            }
        } else {
            p2 = headB; p1 = headA;
            int n = len2 - len1;
            while (n--) {
                p2 = p2->next;
            }
        }
        while (p1 != nullptr) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next; p2 = p2->next;
        }
        return nullptr;
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
    ListNode* new_head = s1.getIntersectionNode(head, head);
    p = new_head;
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}