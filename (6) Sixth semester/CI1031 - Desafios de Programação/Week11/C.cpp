#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, l;
vector<vector<pair<ll, ll>>> adj;

ll timer;
vector<ll> tin, tout, dist;
vector<vector<ll>> up;

void dfs(ll v, ll p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (ll i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];

	for (auto u : adj[v]) {
		if (u.first != p) {
			dist[u.first] = dist[v] + u.second;
			dfs(u.first, v);
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

ll distance(ll a, ll b) {
	return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}

int main () {
	cin.tie(0)->sync_with_stdio(0);
	ll q, t, c;
	cin >> n;

	adj.assign(n + 15, {});

	for (ll i = 1; i < n; ++i) {
		cin >> t >> c;
		adj[t].push_back({i, c});
		adj[i].push_back({t, c});
	}

	preprocess(0);

	cin >> q;
	ll a, b;
	for (ll i = 0; i < q; ++i) {
		cin >> a >> b;

		cout << distance(a, b) << '\n';
	}
}
