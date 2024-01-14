#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    int size;
    ListNode *head;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new(ListNode);
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode * p = head;
        for (int i=0; i<=index; i++) {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode * p = new(ListNode);
        p->val = val;
        p->next = head->next;
        head->next = p;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode * cur = new(ListNode);
        cur->val = val;
        cur->next = nullptr;

        ListNode * p = head;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = cur;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) return this->addAtHead(val);
        if (index == size) return this->addAtTail(val);

        ListNode * cur = new(ListNode);
        cur->val = val;
        ListNode * p = head;
        for (int i=0; i<index; i++) {
            p = p->next;
        }
        cur->next = p->next;
        p->next = cur;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        ListNode * cur = head;
        for (int i=0; i<index; i++) {
            cur = cur->next;
        }
        ListNode * del = cur->next;
        cur->next = cur->next->next;
        delete(del);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(4);
    int res = linkedList.get(1); std::cout << res << std::endl;
    linkedList.addAtHead(1);
    linkedList.addAtHead(5);
    linkedList.deleteAtIndex(3);
    linkedList.addAtHead(7);
    res = linkedList.get(3); std::cout << res << std::endl;
    res = linkedList.get(3); std::cout << res << std::endl;
    res = linkedList.get(3); std::cout << res << std::endl;
    linkedList.addAtHead(1);
    linkedList.deleteAtIndex(4);

    return 0;
}