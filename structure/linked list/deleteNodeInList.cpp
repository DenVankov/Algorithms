#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete(temp);
    }
};

int main() {
    auto *list = new ListNode(2);
    list->next = new ListNode(4);
    list->next->next = new ListNode(3);

    Solution s;
    s.deleteNode(list->next);
    cout << "\n";
    return 0;
}