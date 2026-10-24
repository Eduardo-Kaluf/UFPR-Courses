#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> t[4 * 100015];

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
        return 0;
    if (l <= tl && tr <= r)
        return upper_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
    ll tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, r, x) + query(v*2+1, tm, tr, l, r, x);
}


int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, q;
    if (!(cin >> n >> q)) return 0;

    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    build(vec, 1, 0, n);

    vector<ll> s = vec;
    sort(s.begin(), s.end());

    for (ll ii = 0; ii < q; ii++) {
        ll i, j, k;
        cin >> i >> j >> k;

        ll a = 0, b = n - 1;
        while (a < b) {
            ll mid = (a + b) / 2;
            if (query(1, 0, n, i-1, j, s[mid]) >= k)
                b = mid;
            else
                a = mid + 1;
        }
        cout << s[a] << "\n";
    }
}

