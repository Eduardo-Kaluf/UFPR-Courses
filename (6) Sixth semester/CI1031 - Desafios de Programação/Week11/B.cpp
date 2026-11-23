#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout, dist;
vector<vector<ll>> up;

void dfs(ll v, ll p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (ll i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];

	for (ll u : adj[v]) {
		if (u != p) {
			dist[u] = dist[v] + 1;
			dfs(u, v);
		}
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
	dist.assign(n, 0);
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

ll distance(ll a, ll b) {
	return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	ll q, u, v;
	cin >> n >> q;
	n = n + 1;

	adj.assign(n, {});

	for (ll i = 1; i < n - 1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	preprocess(1);

	ll a, b, c, d;
	for (ll i = 0; i < q; ++i) {
		cin >> a >> b >> c >> d;

		ll l1 = lca(a, c);
		ll l2 = lca(a, d);
		ll l3 = lca(b, c);
		ll l4 = lca(b, d);

		ll x = l1, y = l2;
		if (dist[y] > dist[x]) {
			x = l2;
			y = l1;
		}

		if (dist[l3] > dist[x]) {
			y = x;
			x = l3;
		} else if (dist[l3] > dist[y])
			y = l3;

		if (dist[l4] > dist[x]) {
			y = x;
			x = l4;
		} else if (dist[l4] > dist[y])
			y = l4;

		if (x == y && dist[x] < max(dist[lca(a, b)], dist[lca(c, d)]))
			cout << 0 << '\n';
		else
			cout << distance(x, y) + 1 << '\n';
	}
}
