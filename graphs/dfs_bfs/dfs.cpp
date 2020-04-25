#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void dfsAux(int v, vector<bool>& used) {
        used[v] = true;
        cout << "Vertex v: " << v << "\n";
        for (auto &i: adj[v]) {
            if (!used[i]) {
                dfsAux(i, used);
            }
        }
    }
    graph(int n) {
        this->n = n;
        adj.resize(n);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int v) {
        vector<bool> used(n, false);
        used[v] = true;
        dfsAux(v, used);
    }
private:
    int n;
    vector<vector<int>> adj;
};


int main() {
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.addEdge(4, 5);

    g.dfs(0);
    return 0;
}