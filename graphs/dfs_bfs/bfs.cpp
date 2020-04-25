#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    void bfsAux(int v, vector<bool>& used, vector<int>& queue) {
        used[v] = true;
        queue.push_back(v);
        while (!queue.empty()) {
            v = queue[0];
            cout << "Vertex v: " << v << "\n";
            queue.erase(queue.begin() + 0);
            for (auto &i: adj[v]) {
                if (!used[i]) {
                    used[i] = true;
                    queue.push_back(i);
                }
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
    void bfs(int v) {
        vector<bool> used(n, false);
        used[v] = true;
        vector<int> queue;
        bfsAux(v, used, queue);
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

    g.bfs(0);
    return 0;
}