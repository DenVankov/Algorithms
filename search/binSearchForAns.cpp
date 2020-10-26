#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
const ll MAXX = 5e18;
const ll MOD = 1e9 + 7;

ll n, x_1, x_2, y_1, y_2;

ll ans;

// State of search
bool success(ll t){
    ll fst = t / (x_1 + y_1);
    if(t >= fst * (x_1 + y_1) + x_1){
        fst++;
    }
    
    ll snd = t / (x_2 + y_2);
    if(t >= snd * (x_2 + y_2) + x_2){
        snd++;
    }
    
    if(fst + snd >= n) return true;
    return false;
}


void binSearch() {
    ll l = 0, r = MAXX, m;
    while(l <= r){
        m = (r + l) / 2;
        if(success(m)){
            ans = m;
            r = m - 1;
        }else {
            l = m + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n;
    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
    binSearch();
    cout << ans << "\n";

    return 0;
}
