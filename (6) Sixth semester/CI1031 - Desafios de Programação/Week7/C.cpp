#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1000000000;
vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> & d) {
	ll n = adj.size();
	d.assign(n, INF);
	d[s] = 0;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
	pq.push({0, s});

	while (!pq.empty()) {
		auto [dv, v] = pq.top();

		pq.pop();

		if (dv != d[v])
			continue;

		for (auto [to, len] : adj[v]) {
			if (len + dv < d[to]) {
				d[to] = len + dv;
				pq.push({len + dv, to});
			}
		}
	}
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, c, k;

	cin >> n >> m >> c >> k;
	adj.assign(n, vector<pair<ll, ll>>(0));
	for (ll i = 0; i < m; i++) {
		ll u, v, p;
		cin >> u >> v >> p;

		if (u > c - 1 && v > c - 1) {
			adj[u].push_back({v, p});
			adj[v].push_back({u, p});
			continue;
		}

		if (u <= c - 1 && v <= c - 1) {
			if (u == v + 1)
				adj[v].push_back({u, p});
			else if (v == u + 1)
				adj[u].push_back({v, p});
			continue;
		}

		if (u <= c -1) {
			adj[v].push_back({u, p});
		}
		else if (v <= c -1) {
			adj[u].push_back({v, p});
		}
	}

	vector<ll> v(n + 1);
	dijkstra(k, v);
	cout << v[c - 1];
}

