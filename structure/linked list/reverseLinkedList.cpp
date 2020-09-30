#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *par = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *new_node = cur->next;
            cur->next = par;
            par = cur;
            cur = new_node;
        }
        return par;
    }
};

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        if (cur->next != nullptr)
            cout << cur->val << "->";
        else
            cout << cur->val << "\n";
        cur = cur->next;
    }
}

int main() {
    auto *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    printList(list);
    Solution s;
    list = s.reverseList(list);
    printList(list);

    return 0;
}