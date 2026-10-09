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

struct edge {
	ll a;
	ll b;
	ll w;
};

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll p, t;
	cin >> p >> t;
	adj.assign(p, vector<pair<ll, ll>>(0));
	vector<edge> aux;
	for (int i = 0; i < t; i++) {
		ll a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
		aux.push_back({a, b, l});
	}

	vector<ll> init;
	vector<ll> final;
	dijkstra(0, init);
	dijkstra(p - 1, final);

	ll total = init[p - 1];
	ll answer = 0;
	for (int i = 0; i < t; i++) {
		if (init[aux[i].a] + final[aux[i].b] + aux[i].w == total ||
			init[aux[i].b] + final[aux[i].a] + aux[i].w == total) {
			answer += aux[i].w;
		}
	}

	cout << answer * 2;
}

