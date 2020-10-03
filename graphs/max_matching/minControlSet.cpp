#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> adj;
vector<vector<long long>> direct_adj;
long long used[80002];
long long par[80002];
long long back_par[80002];

long long cnt;

void dfs(long long u) {
    if (used[u] == cnt)
        return;
    used[u] = cnt;
    for (auto &v : direct_adj[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    long long n, m, a;
    cin >> m >> n;

    adj.resize(80002);
    direct_adj.resize(80002);

    for (int i = 0; i < 80002; ++i) {
        par[i] = -1;
        back_par[i] = - 1;
        used[i] = 0;
    }
    long long k;
    for (long long i = 1; i < m + 1; ++i) {
        cin >> k;
        for (long long j = 0; j < k; ++j) {
            cin >> a;
            adj[i].push_back(a + m);
            adj[a + m].push_back(i);
        }
    }
    // Input max pair matching
    for (long long i = 1; i < m + 1; ++i) {
        cin >> a;
        if (a != 0) {
            par[a + m] = i;
            back_par[i] = a + m;
        }
    }
    // Orientation edges left to right
    for (long long i = 1; i < m + 1; ++i) {
        for (long long u = 0; u < adj[i].size(); ++u) {
            if (par[adj[i][u]] != i)
                direct_adj[i].push_back(adj[i][u]);
        }
    }
    // Orientation edges right to left
    for (long long i = 1 + m; i < m + n + 1; ++i) {
        for (long long u = 0; u < adj[i].size(); ++u) {
            if (par[i] == adj[i][u])
                direct_adj[i].push_back(adj[i][u]);
        }
    }
    cnt = 1;
    // Dfs for all not in par match
    for (long long i = 1; i < m + 1; ++i) {
        if (back_par[i] == -1) {
            dfs(i);
        }
    }

    vector<long long> lminus;
    vector<long long> rplus;

    // Get vectors for left side
    for (long long i = 1; i < m + 1; ++i) {
        if (used[i] == 0)
            lminus.push_back(i);
    }
    // Get vectors for right side
    for (long long i = 1 + m; i < m + n + 1; ++i) {
        if (used[i] > 0)
            rplus.push_back(i);
    }

    cout << lminus.size() + rplus.size() << "\n";
    cout << lminus.size() << " ";
    for (auto &j: lminus) {
        cout << j << " ";
    }
    cout << "\n" << rplus.size() << " ";
    for (auto &j: rplus) {
        cout << j - m << " ";
    }
    cout << "\n";

    return 0;
}

//5 4
//2 1 3
//1 4
//2 1 2
//3 2 3 4
//3 2 3 4
//1 0 2 3 4