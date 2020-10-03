#include <bits/stdc++.h>

using namespace std;

#define P pair
#define F first
#define S second

typedef long long ll;

const ll MX = 1e15;
const ll MAXX = 1e5 + 5;

ll n, query;
vector<P<ll,ll>> tree;

void upd(ll k, ll x) {
    k += n;
    tree[k].F = x;
    tree[k].S = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k].F = min(tree[2 * k].F, tree[2 * k + 1].F);
        tree[k].S = max(tree[2 * k].S, tree[2 * k + 1].S);
    }
}

ll sum(ll a, ll b) {
    ll mx = -MX;
    ll mn = MX;
    a += n;
    b += n;
    while (a <= b) {
        if (a % 2 == 1) {
            mx = max(mx, tree[a].S);
            mn = min(mn,tree[a++].F);
        }
        if (b % 2 == 0){
            mx = max(mx, tree[b].S);
            mn = min(mn,tree[b--].F);
        }
        a /= 2;
        b /= 2;
    }
    return abs(mx - mn);
}

int main() {
    n = MAXX;
    vector<ll> v(n);
    for (ll i = 1; i <= n; ++i) {
        v[i - 1] = (i * i) % (12345) + (i * i * i) % (23456);
    }

    ll i = 1;
    while (i < n) {
        i *= 2;
    }

    n = i;

    tree.resize(2 * n + 5);
    for (i = 0; i < v.size(); ++i) {
        upd(i, v[i]);
    }

    cin >> query;
    ll a, b;
    for (i = 0; i < query; ++i) {
        cin >> a >> b;
        if (a < 0) {
            a = -1 * a;
            a--;
            upd(a, b);
        } else {
            a--;
            b--;
            cout << sum(a, b) << "\n";
        }
    }
    return 0;
}