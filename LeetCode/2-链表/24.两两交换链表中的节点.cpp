#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int cnt = 0;
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* pnext = nullptr;
        if (head->next != nullptr && head->next->next != nullptr) {
            pnext = swapPairs(head->next->next);
        }else {
            pnext = p2->next;
        }
        
        p2->next = p1;
        p1->next = pnext;
        return p2;
    }
};

class Solution2 {
private:
    int cnt = 0;
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* p2 = head->next;
        head->next = swapPairs(p2->next);
        p2->next = head;
        return p2;
    }
};

int main() {
    ListNode *head; 
    ListNode *p;
    ListNode *pre;
    head = new(ListNode); head->val = 1; pre = head;
    p = new(ListNode); p->val = 2; pre->next = p; pre = p;
    p = new(ListNode); p->val = 3; pre->next = p; pre = p;
    p = new(ListNode); p->val = 4; pre->next = p; pre = p;

    Solution s1;
    ListNode* new_head = s1.swapPairs(head);
    p = new_head;
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}