#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3F3F3F3F3F3F3F3FLL;

struct edge {
    uint32_t from;
    uint32_t to;
    long long cost;
};

void dfs(int v, vector<edge> &graph, vector<int> &used, vector<long long>& d) {
    used[v] = 1;
    for (auto &j: graph) {
        if (v == j.from - 1)
            if (!used[j.to - 1])
                dfs(j.to - 1, graph, used, d);
    }
}


vector<long long> BellmanFord(vector<edge> &graph, uint32_t n, uint32_t start) {
    vector<long long> d(n, INF);

    d[start] = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool any = false;
        for (auto &j : graph)
            if (d[j.from - 1] < INF)
                if (d[j.to - 1] > d[j.from - 1] + j.cost) {
                    d[j.to - 1] = d[j.from - 1] + j.cost;
                    any = true;
                }
        if (!any) break;
    }

    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<edge> graph;
    uint32_t n, m, start, finish = 0;
    cin >> n >> m >> start;

    graph.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> graph[i].from >> graph[i].to >> graph[i].cost;
    }

    vector<long long> d = BellmanFord(graph, n, start - 1);
    vector<int> used(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (auto &j: graph) {
            if ((d[j.from - 1] < INF) && (d[j.to - 1] > d[j.from - 1] + j.cost) && !used[j.to - 1])
                dfs(j.to - 1, graph, used, d);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (d[i] == INF)
            cout << "*\n";
        else if (used[i])
            cout << "-\n";
        else
            cout << d[i] << "\n";
    }

    return 0;
}