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

### Policy based data structures
```c++
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using namespace __gnu_pbds;
//less = set
typedef tree<ll,null_type,less<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
//less_equal = multiset
typedef tree<ll,null_type,less_equal<ll>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_multiset;

ll idx = s.order_of_key(key);
auto it = s.find_by_order(idx);
cout << idx << " " << *it << "\n";
```
