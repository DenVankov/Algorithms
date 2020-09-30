#include <bits/stdc++.h>

using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize): arr(maxSize) {
        size = maxSize;
        cap = 0;
    }

    void push(int x) {
        if (cap < size)
            arr[cap++] = x;
    }

    int pop() {
        if (cap != 0)
            return arr[--cap];
        else
            return -1;
    }

    void increment(int k, int val) {
        if (k > size)
            k = size;
        for (int i = 0; i < k; ++i) {
            arr[i] += val;
        }
    }
private:
    int size;
    int cap;
    vector<int> arr;
};