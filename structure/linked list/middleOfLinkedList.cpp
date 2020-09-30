#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    int findSize(ListNode* head, int size) {
        if (head->next == nullptr) {
            return size + 1;
        } else {
            return findSize(head->next, size + 1);
        }
    }

    ListNode* win(ListNode* head, int size) {
        if (size == 1) {
            return head;
        } else {
            return win(head->next, size - 1);
        }
    }

    ListNode* middleNode(ListNode* head) {
        int size = findSize(head, 0);
        return win(head, size / 2 + 1);
    }
};

int main() {
    Solution s;
    ListNode a(1);
    a.next = new ListNode(2);
    a.next->next = new ListNode(3);
    a.next->next->next = new ListNode(4);
    a.next->next->next->next = new ListNode(5);
    s.middleNode(&a);
    return 0;
}