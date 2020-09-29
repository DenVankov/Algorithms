#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define pb push_back

struct node {
    int cnt;
    int idx;
    map<int, int> adj;

    node() {
        cnt = 0;
    }
};

int k;
int ans;
int last_node = 0;
int last_idx = 0;
node t[5000005];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';

        if (t[cur].adj.find(ch) == t[cur].adj.end()) {
            last_node += 1;
            t[cur].adj[ch] = last_node;
        }
        cur = t[cur].adj[ch];
    }
    t[cur].cnt++;
    t[cur].idx = last_idx++;
}

void _find(int cur) {
    if(k <= 0) return;

    if (t[cur].cnt > 0) {
        k -= t[cur].cnt;
        if(k <= 0){
            ans = t[cur].idx;
            return;
        }
    }

    for (auto &[key, v] : t[cur].adj) {
        _find(v);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(isdigit(s[0])){
            k = stoi(s);
            _find(0);
            cout << strs[ans] << "\n";
        } else {
            strs.pb(s);
            add(s);
        }

    }
    return 0;
}