#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
    }

    int pop() {
        if (!q.empty()) {
            while(q.size() != 1) {
                q2.push(q.front());
                q.pop();
            }
            int out = q.front();
            q.pop();
            while(!q2.empty()) {
                q.push(q2.front());
                q2.pop();
            }
            return out;
        }
        return -1;
    }

    int top() {
        if (!q.empty()) {
            while(q.size() != 1) {
                q2.push(q.front());
                q.pop();
            }
            int out = q.front();
            q.pop();
            q2.push(out);
            while(!q2.empty()) {
                q.push(q2.front());
                q2.pop();
            }
            return out;
        }
        return -1;
    }

    bool empty() {
        return q.empty();
    }
private:
    queue<int> q, q2;
};