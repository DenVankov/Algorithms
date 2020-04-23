#include <bits/stdc++.h>

using namespace std;

long long d[105][105];
long long gr[105][105];
const int INF = 1e9;

void floyd(int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = gr[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> gr[i][j];
            if (gr[i][j] == -1)
                gr[i][j] = INF;
        }
    }

    floyd(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}