#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

double Prim(int n, vector<vector<pair<int, int>>>& gr) {
    vector<double > dist(n, INF);
    vector<int> used(n, 0);
    dist[0] = 0;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int u = 0; u < n; ++u) {
            if(!used[u] && (v == -1 || dist[v] > dist[u])) {
                v = u;
            }
        }
        if (v == -1)
            break;
        ans += dist[v];
        used[v] = 1;
        for(auto &p: gr[v]) {
            int u = p.first;
            int w = p.second;
            if (dist[u] > w)
                dist[u] = w;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);


    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> gr(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        gr[u].push_back({v, w});
        gr[v].push_back({u,w});
    }
    cout << Prim(n, gr) << "\n";
    return 0;
}