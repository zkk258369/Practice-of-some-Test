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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = head;
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* del = NULL;
        while (cur != NULL) {
            if (cur->val == val) {
                if (cur == new_head) {
                    new_head = cur->next;
                } else {
                    pre->next = cur->next;
                }
                del = cur;
                cur = cur->next;
                delete (del);
            }else {
                pre = cur;
                if (cur == new_head) {
                    pre = new_head;
                }
                cur = cur->next;
            }
        }
        return new_head;
    }
};

// 递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    };
};

int main() {
    // [1,2,6,3,4,5,6]
    ListNode *head; 
    ListNode *p;
    ListNode *pre;
    head = new(ListNode); head->val = 1; pre = head;
    p = new(ListNode); p->val = 2; pre->next = p; pre = p;
    p = new(ListNode); p->val = 6; pre->next = p; pre = p;
    p = new(ListNode); p->val = 3; pre->next = p; pre = p;
    p = new(ListNode); p->val = 4; pre->next = p; pre = p;
    p = new(ListNode); p->val = 5; pre->next = p; pre = p;
    p = new(ListNode); p->val = 6; pre->next = p; pre = p;

    Solution s1;
    ListNode* new_head = s1.removeElements(head, 6);
    p = new_head;
    while(p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;

    return 0;
}