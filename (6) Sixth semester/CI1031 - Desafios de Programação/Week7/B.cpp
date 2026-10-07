#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n;
	cin >> n;

	vector<ll> w(n + 1);
	for (ll i = 1; i <= n; i++)
		cin >> w[i];

	ll m;
	cin >> m;

	vector<vector<ll>> adj(n + 1);
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<ll> vis(n + 1, 0);
	queue<ll> queues;
	vis[1] = 1;
	queues.push(1);
	while (!queues.empty()) {
		ll u = queues.front(); queues.pop();
		for (ll v : adj[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				queues.push(v);
			}
		}
	}

	ll q;
	cin >> q;
	while (q--) {
		ll u;
		cin >> u;
		ll a = w[u] - w[1];
		if (a < 3) {
			cout << "Não, Edsger...\n";
		}
		else {
			cout << a << '\n';
		}
	}
}
