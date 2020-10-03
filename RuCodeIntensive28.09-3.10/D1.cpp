#include <bits/stdc++.h>

using namespace std;

vector<string> vec;

struct node {
    int nd;
    map <int, int> adj;
    node() {
        nd = 0;
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
        cur = t[cur].adj[ch];
    }
    t[cur].nd += 1;
}

bool good(int idx, int left, int right) {
    int cur = 0;
    for (int i = left; i < right; ++i) {
        int ch = vec[idx][i] - 'a';
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            return false;
        }
        cur = t[cur].adj[ch];
    }
    if (t[cur].nd > 0)
        return true;

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vec.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vec[i] = s;
        add(s);
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 1; j < vec[i].size(); ++j) {
            ans += good(i, 0, j) * good(i, j, vec[i].size());
        }
        cout << ans << "\n";
    }
    return 0;
}
