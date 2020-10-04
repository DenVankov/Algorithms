# Algorithms
Collection of various algorithms and problem solving

### Standart template
```c++
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define P pair

typedef long double ld;
typedef long long ll;
const ll MAXX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        // Smth
    }

    return 0;
}
```
### Compilation flags
```
g++ a.cpp -o a -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
```

### Freopen
```c++
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```
