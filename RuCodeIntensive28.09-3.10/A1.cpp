#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

long long out = 0;

struct node {
    int cnt;
    map < int, int > adj;
    node() {
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
        cur = t[cur].adj[ch];
    }
    t[cur].cnt += 1;
    if (t[cur].cnt == 1)
        out++;
}

void del(string &s) {
    int cur = 0;
    for (char i : s) {
        int ch = i - 'a';
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            return;
        }
        cur = t[cur].adj[ch];
    }
    if (t[cur].cnt > 0)
        t[cur].cnt -= 1;
}

bool good(string &s) {
    int cur = 0;
    for (char i : s){
        int ch = i - 'a';
        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            return false;
        }
        cur = t[cur].adj[ch];
    }
    if (t[cur].cnt > 0)
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        add(s);
    }
    cout << out << "\n";
    return 0;
}