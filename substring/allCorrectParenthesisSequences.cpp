#include <bits/stdc++.h>

using namespace std;

void generate(int n, vector<char> &cur_seq, int balance=0, int idx=0) {
    if (idx == 2 * n) {
        for (auto &j : cur_seq) {
            cout << j;
        }
        cout << "\n";
    } else {
        if (balance == 2 * n - idx) {
            cur_seq[idx] = ')';
            balance--;
            generate(n, cur_seq, balance, idx + 1);
        } else {
            cur_seq[idx] = '(';
            balance++;
            generate(n, cur_seq, balance, idx + 1);

            if (balance > 1) {
                cur_seq[idx] = ')';
                balance -= 2;
                generate(n, cur_seq, balance, idx + 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> seq(2 * n);
    generate(n, seq);
    return 0;
}
