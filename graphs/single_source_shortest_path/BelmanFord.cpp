#include <bits/stdc++.h>

using namespace std;

const long long INF = 10e12;

struct edge {
    uint32_t from;
    uint32_t to;
    int64_t cost;
};

int64_t BellmanFord(vector<edge> &graph, uint32_t n, uint32_t start, uint32_t finish)
{
    vector<int64_t> d (n, INF);

    d[start] = 0;
    for (;;) {
        bool any = false;
        for (auto & j : graph)
            if (d[j.from - 1] < INF)
                if (d[j.to - 1] > d[j.from - 1] + j.cost) {
                    d[j.to - 1] = d[j.from - 1] + j.cost;
                    any = true;
                }
        if (!any)  break;
    }
    return d[finish];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<edge> graph;
    uint32_t n, m, start, finish = 0;
    cin >> n >> m >> start >> finish;
    graph.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> graph[i].from >> graph[i].to >> graph[i].cost;
    }

    int64_t ans = BellmanFord(graph, n, start - 1, finish - 1);
    if (ans == INF) {
        cout << 1000000000000000000 << "\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}