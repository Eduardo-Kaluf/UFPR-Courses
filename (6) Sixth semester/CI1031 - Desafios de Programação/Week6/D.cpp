#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#include <iostream>
#include <vector>
using namespace std;


vector<vector<ll>> adj((2 * 10e5) + 15);
vector<bool> visited((2 * 10e5) + 15);
ll diam = 0;

ll sol(ll r, ll depth) {
	visited[r] = true;

	if (adj[r].size() == 0) {
		return 0;
	}

	ll max = 0;
	ll second_max = 0;
	for (ll u : adj[r]) {
		if (!visited[u]) {
			ll ret = sol(u, depth);

			if (max < ret) {
				second_max = max;
				max = ret;
				continue;
			}

			if (second_max < ret) {
				second_max = ret;
			}
		}
	}

	if (diam < max + second_max) {
		diam = max + second_max;
	}

	return max + 1;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, u, v;

	cin >> n;

	for (ll i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	visited[1] = true;
	sol(1, 0);

	cout << diam;
}

