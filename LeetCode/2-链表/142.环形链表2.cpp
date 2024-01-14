#include <iostream>
#include <set>

using std::set;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* p1 = head;

        bool circle = false;
        set<ListNode*> pset;
        while (p1 != nullptr) {
            if (pset.find(p1) != pset.end()) {
                circle = true;
                break;
            } else {
                pset.insert(p1);
            }
            p1 = p1->next;
        }
        return circle ? p1 : nullptr;
    }
};

int main() {
    return 0;
}