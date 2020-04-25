#include<bits/stdc++.h>
using namespace std;

typedef int type;

type search(type target, vector<type>& v) {
    int l = 0;
    int r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    cout << "Vector must be sorted!\n";
    for (auto &i: v) {
        cin >> i;
    }
    cout << search(target, v) << "\n";

    return 0;
}