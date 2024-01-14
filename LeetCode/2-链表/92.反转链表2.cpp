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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pre = head;
        ListNode* rpre = head;
        ListNode* pleft = nullptr;
        ListNode* pright = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = head;
        for (int i=1; i<=right; i++) {
            if (i == left) {
                rpre = pre;
                pleft = cur;
            }
            if (i == right) {
                pright = cur;
                next = cur->next;
            }
            pre = cur;
            cur = cur->next;
        }
        ListNode* newHead = reverse(pleft, next);
        if (left > 1) {
            rpre->next = newHead;
        } else {
            head = newHead;
        }
        
        pleft->next = next;
        return head;
    }
    ListNode* reverse(ListNode* head, ListNode* end) {
        if (head == end || head->next == end) {
            return head;
        }
        ListNode* newHead = reverse(head->next, end);
        head->next->next = head;
        head->next = end;
        return newHead;
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
    ListNode* new_head = s1.reverseBetween(head, 1, 2);
    p = new_head;
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}