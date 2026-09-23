#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#include <iostream>
#include <vector>
using namespace std;


// https://cp-algorithms.com/graph/breadth-first-search.html
// https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
class UnionFind {
	vector<pair<ll, ll>> parent;
public:
	UnionFind(const vector<ll>& vals) {

		ll size = vals.size();

		parent.resize(size);

		// Initialize the parent array with each
		// element as its own representative

		for (ll i = 0; i < size; i++) {
			parent[i] = {vals[i], i}; // {value, idx}
		}
	}

	// Find the representative (root) of the
	// set that includes element i
	pair<ll, ll> find(ll i) {

		// If i itself is root or representative
		if (parent[i].second == i) {
			return parent[i];
		}

		// Else recursively find the representative
		// of the parent
		pair<ll, ll> root = find(parent[i].second);
		parent[i].second = root.second;
		return root;
	}

	// Unite (merge) the set that includes element
	// i and the set that includes element j
	void unite(ll i, ll j) {

		// Representative of set containing i
		pair<ll, ll> irep = find(i);

		// Representative of set containing j
		pair<ll, ll> jrep = find(j);

		// Make the representative of i's set
		// be the representative of j's set
		if (irep.second != jrep.second) {
			parent[irep.second].second = jrep.second;
		}
	}
};

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> perm(n + 1);
	for (ll i = 1; i < n + 1; i++)
		cin >> perm[i];

	ll a, b;
	UnionFind uf(perm);
	for (ll i = 0; i < m; i++) {
		cin >> a >> b;
		uf.unite(a, b);
	}

	map<ll, vector<ll>> groups;
	map<ll, vector<ll>> idx;
	for (ll i = 1; i < n + 1; i++) {
		pair<ll, ll> u = uf.find(i);
		groups[u.second].push_back(perm[i]);
		idx[u.second].push_back(i);
	}

	for (auto& pair : groups)
		sort(pair.second.rbegin(), pair.second.rend());

	for (auto& pair : idx)
		sort(pair.second.begin(), pair.second.end());

	vector<ll> ans(n + 1);
	for (auto& [key, g_vec] : groups) {
		auto& i_vec = idx[key];

		for (size_t j = 0; j < g_vec.size(); ++j) {
			ans[i_vec[j]] = g_vec[j];
		}
	}

	for (int i = 1; i < n + 1; i++) {
		cout << ans[i] << " ";
	}
}
