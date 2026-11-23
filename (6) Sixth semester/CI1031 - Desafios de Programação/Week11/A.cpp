#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, l;
vector<vector<ll>> up;

ll findKthAncestor(ll v, ll k) {
	for (ll i = 0; i < l; ++i)
		if (k >> i & 1)
			v = up[v][i];
	return v;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	ll q, t;
	cin >> n >> q;

	n = n + 1;
	l = 30;
	up.assign(n, vector<ll>(l));

	for (ll v = 1; v < n; ++v) {
		cin >> t;
		up[v][0] = t;
	}

	for (ll i = 1; i < l; ++i)
		for (ll v = 1; v < n; ++v)
			up[v][i] = up[up[v][i-1]][i-1];

	ll x, k;
	for (ll i = 0; i < q; ++i) {
		cin >> x >> k;
		cout << findKthAncestor(x, k) << '\n';
	}
}
