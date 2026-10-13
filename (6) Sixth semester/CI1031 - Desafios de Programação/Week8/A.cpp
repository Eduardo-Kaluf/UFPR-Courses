#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> t[4 * 100015];
ll INF = 9876454321;

// [tl, tl)
// v = index
void build(const vector<ll>& a, ll v, ll tl, ll tr) {
    if (tr - tl == 1) {
        t[v] = vector<ll>(1, a[tl]);
    } else { 
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r, ll x) {
    if (r <= tl || tr <= l)
        return INF;
    if (l <= tl && tr <= r) {
        if (x >= tl && x < tr)
            return t[v][x];
        return INF;
    }
    ll tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, r, x), 
               query(v*2+1, tm, tr, l, r, x));
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, q;
    if (!(cin >> n >> q)) return 0;

    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    build(vec, 1, 0, n);

    for (ll ii = 0; ii < q; ii++) {
        ll i, j, k;
        cin >> i >> j >> k;
        
        ll ans = query(1, 0, n, i, j, k);
        
        if (ans == INF)
            cout << -1 << "\n"; 
        else
            cout << ans << "\n";
    }
}

