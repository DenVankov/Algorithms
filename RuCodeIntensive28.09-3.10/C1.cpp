#include <bits/stdc++.h>

using namespace std;

long long out = 0;
string out_s;

struct node {
    int cnt;
    int term;
    map<int, int> adj;

    node() {
        term = false;
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
            out++;
        }
        t[cur].cnt += 1;
        cur = t[cur].adj[ch];
    }
    t[cur].term = true;
    t[cur].cnt += 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int j = s.size() - 1; j >= 0; --j) {
        string tmp = s.substr(j, s.size() - j);
        add(tmp);
    }
    cout << out << "\n";
    return 0;
}
