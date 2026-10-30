#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;

	cin >> n;

	vector<ll> v(n + 1);
	vector<ll> degreee(n + 1, 0);

	for (ll i = 1; i <= n; i++) {
		cin >> v[i];
		degreee[v[i]]++;
	}

	queue<ll> q;
	for (ll i = 1; i <= n; i++)
		if (degreee[i] == 0) q.push(i);

	ll popped = 0;
	while (!q.empty()) {
		ll u = q.front();
		q.pop();

		popped++;

		if (--degreee[v[u]] == 0)
			q.push(v[u]);
	}

	cout << n - popped << '\n';
}