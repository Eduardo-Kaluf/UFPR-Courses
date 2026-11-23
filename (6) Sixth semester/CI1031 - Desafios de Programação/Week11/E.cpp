#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

void dfs(ll v, ll p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (ll i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];

	for (ll u : adj[v]) {
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (ll i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(ll root) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<ll>(l + 1));
	dfs(root, root);
}

ll findKthAncestor(ll v, ll k) {
	for (ll i = 0; i <= l; ++i)
		if (k >> i & 1)
			v = up[v][i];
	return v;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	ll q, e;
	cin >> n >> q;

	n = n + 1;
	adj.assign(n, {});

	for (ll i = 2; i < n; ++i) {
		cin >> e;
		adj[e].push_back(i);
		adj[i].push_back(e);
	}

	preprocess(1);

	ll x, k;
	for (ll i = 0; i < q; ++i) {
		cin >> x >> k;

		ll ans = findKthAncestor(x, k);
		if (ans == 1 && findKthAncestor(x, k - 1) == 1)
			ans = -1;
		cout << ans << '\n';
	}
}
