#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1000000000;
vector<vector<pair<ll, ll>>> adj;

ll dijkstra(ll s, vector<ll> & d) {
	ll n = adj.size();
	d.assign(n, INF);
	d[s] = 0;

	ll max_num = -INF;

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

	return *max_element(d.begin(), d.end());;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m;
	cin >> n >> m;

	adj.assign(n, vector<pair<ll, ll>>(0));

	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<ll> ans(n);
	ll max_path = INF;
	for (ll i = 0; i < n; i++) {
		ll result = dijkstra(i, ans);
		max_path = min(max_path, result);
	}

	cout << max_path;
}

