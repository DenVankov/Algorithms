#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node* next;
};

int listlen(Node *head) {
    int cnt = 0;
    Node* cur = head;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

Node *listIntersection(Node* head1, Node* head2) {
    int s1 = listlen(head1);
    int s2 = listlen(head2);

    Node* cur1 = head1;
    Node* cur2 = head2;
    if (s1 > s2) {
        int diff = s1 - s2;
        while (diff) {
            cur1 = cur1->next;
            diff--;
        }
    } else {
        int diff = s2 - s1;
        while (diff) {
            cur2 = cur2->next;
            diff--;
        }
    }

    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1 == nullptr ? nullptr : cur1;
}

int main() {

    Node* newNode;

    Node* head1 = new Node();
    head1->val = 10;

    Node* head2 = new Node();
    head2->val = 3;

    newNode = new Node();
    newNode->val = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->val = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->val = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->val = 25;
    head1->next = newNode;
    head2->next->next->next->next = newNode;

    newNode = new Node();
    newNode->val = 30;
    head1->next->next = newNode;

    head1->next->next->next = nullptr;

    cout << listIntersection(head1, head2)->val << "\n";

    return 0;
}