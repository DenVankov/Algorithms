#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    MinStack() : stack(0){
        size = 0;
    }

    void push(int x) {
        if (size == 0) {
            stack.resize(1);
            stack[size].first = x;
            stack[size].second = x;
            min = x;
        } else {
            stack.resize(size + 1);
            stack[size].first = x;
            if (x < min) {
                min = x;
                stack[size].second = x;
            } else
                stack[size].second = min;
        }
        size++;
    }

    void pop() {
        if (size != 0) {
            if (size != 1)
                min = stack[size - 2].second;
            else
                min = 0;
            stack.erase(stack.begin() + size - 1);
            size--;
        }
    }

    int top() {
        return stack[size - 1].first;
    }

    int getMin() {
        return min;
    }

private:
    vector<pair<int,int>> stack;
    int size;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    auto* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin();
    minStack->pop();
    minStack->top();
    minStack->getMin();
    return 0;
}