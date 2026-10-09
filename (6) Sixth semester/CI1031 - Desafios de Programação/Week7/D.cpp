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
			ll biggest = max(len, dv);

			if (biggest < d[to]) {
				d[to] = biggest;
				pq.push({biggest, to});
			}
		}
	}
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, a, b, w;

	cin >> n >> m;

	adj.assign(n + 1, vector<pair<ll, ll>>(0));

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	ll q;
	cin >> q;
	vector<vector<ll>> ans(n + 1);

	for (int i = 1; i <= n; i++) {
		dijkstra(i, ans[i]);
	}

	while (q--) {
		cin >> a >> b;
		cout << ans[a][b] << '\n';
	}
}

