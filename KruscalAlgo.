#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> sz;

int get(int v) {
    if (par[v] == v)
        return v;

    par[v] = get(par[v]);
    return par[v];
}

void _union(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v)
        return;
    if (sz[u] > sz[v])
        swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);

    int n, m;
    cin >> n >> m;
    par.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }

    vector<pair<int, pair<int, int>>> gr(m);
    for (int i = 0; i < m; ++i) {
        cin >> gr[i].second.first >> gr[i].second.second >> gr[i].first;
        --gr[i].second.first;
        --gr[i].second.second;
    }
    sort(gr.begin(), gr.end());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int w = gr[i].first;
        int u = gr[i].second.first;
        int v = gr[i].second.second;
        if (get(u) != get(v)) {
            ans += w;
            _union(u, v);
        }
    }
    cout << ans << "\n";
}