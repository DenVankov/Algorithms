#include <bits/stdc++.h>

using namespace std;

int out_idx;
int k = 0;
int current_idx = 1;
vector<string> vec;

struct node {
    int cnt;
    int idx;
    int nd;
    map <int, int> adj;
    node() {
        nd = 0;
        idx = -1;
        cnt = 0;
    }
};

int last_node = 0;
node t[5000005];

void add(string &s) {
    int cur = 0;
    for (char i : s) {
        int ch = i - 'a';

        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }
        t[cur].cnt += 1;
        cur = t[cur].adj[ch];
    }
    t[cur].nd += 1;
    t[cur].idx = current_idx;
    current_idx += 1;
    t[cur].cnt += 1;
}

void find_(int cur) {
    if (t[cur].nd >= k && cur != 0) {
        out_idx = t[cur].idx;
        return;
    }
    if (t[cur].nd)
        k -= t[cur].nd;
    int next_step;
    int pre_next;
    for (auto &[key, v] : t[cur].adj) {
        pre_next = next_step;
        next_step = v;
        if (k <= 0) {
            next_step = pre_next;
            out_idx = t[next_step].idx;
            break;
        }
        if (k > t[v].cnt) {
            k -= t[v].cnt;
        } else {
            next_step = v;
            break;
        }
    }
    find_(next_step);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (isdigit(s[0])) {
            k = 0;
            k = stoi(s);
            find_(0);
            cout << vec[out_idx - 1]  << "\n";
        } else {
            vec.push_back(s);
            add(s);
        }
    }
    return 0;
}
