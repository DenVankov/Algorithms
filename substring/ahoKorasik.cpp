#include <bits/stdc++.h>

using namespace std;

struct node {
    int par;
    int ch;
    int adj[26];
    int go[26];
    int link;
    int dp;
    int cnt;
    int last_idx;
    node() {
        last_idx = -1;
        par = -1;
        ch = -1;
        dp = -1;
        cnt = 0;
        link = -1;
        for (int i = 0; i < 26; ++i){
            adj[i] = go[i] = -1;
        }
    }
};

node t[500005];
vector<string> vec;
vector<bool> used;

int link(int x);

int go(int x, int c) {
    if (t[x].go[c] != -1) {
        return t[x].go[c];
    } else if (t[x].adj[c] != -1) {
        return t[x].go[c] = t[x].adj[c];
    } else {
        if (x == 0) {
            return t[x].go[c] = 0;
        }
        return t[x].go[c] = go(link(x), c);
    }
}

int link(int x) {
    if (t[x].link != -1) {
        return t[x].link;
    } else if (x == 0 || t[x].par == 0) {
        return t[x].link = 0;
    } else {
        return go(link(t[x].par), t[x].ch);
    }
}

int dp(int x) {
    if (t[x].cnt) {
        used[t[x].last_idx] = true;
    }
    if (t[x].dp != -1) {
        return t[x].dp;
    } else {
        return t[x].dp = t[x].cnt + (x == 0 ? 0 : dp(link(x)));
    }
}

int last_node;
int in_vector;

void add(string &s) {
    int cur = 0;
    for (char i : s) {
        int ch = i - 'a';
        if (t[cur].adj[ch] == -1) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
            t[last_node].par = cur;
            t[last_node].ch = ch;
        }
        cur = t[cur].adj[ch];
    }
    t[cur].last_idx = in_vector++;
    t[cur].cnt += 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    string T;
    cin >> T;
    int n;
    cin >> n;
    vec.resize(n + 1);
    used.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        add(s);
        vec[i - 1] = s;
    }

    int cur = 0;
    for(int i = 0; i < T.size(); i++){
        cur = go(cur, T[i] - 'a');
        dp(cur);
    }
    for (int i = 0; i < n; ++i) {
        if (used[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
