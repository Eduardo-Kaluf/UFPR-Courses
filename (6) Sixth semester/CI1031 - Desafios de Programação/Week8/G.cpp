#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MOD = 1e9 + 7;

ll power(ll b, ll e) {
	b %= MOD; ll r = 1;
	for (; e > 0; e >>= 1, b = b * b % MOD)
		if (e & 1) r = r * b % MOD;
	return r;
}

ll max_fact = 10000;
int main () {
	cin.tie(0)->sync_with_stdio(0);

	vector<ll> fat(max_fact + 1), inv(max_fact + 1);
	fat[0] = 1;
	for (ll i = 1; i <= max_fact; ++i)
		fat[i] = fat[i - 1] * i % MOD;

	inv[max_fact] = power(fat[max_fact], MOD - 2);
	for (ll i = max_fact; i >= 1; --i)
		inv[i - 1] = inv[i] * i % MOD;

	ll n, c;

	cin >> n >> c;
	vector<ll> B(n + 1);
	vector<ll> free(n + 1, n);
	pair<ll, ll> corinthians;

	for (int i = 1 ; i <= n ; i++)
		cin >> B[i];

	for (int i = 1; i <= c; i++) {
		cin >> corinthians.first >> corinthians.second;
		free[corinthians.second]--;
	}

	ll ans = 1;
	for (int i = 1 ; i <= n ; i++) {
		ans = ans * fat[B[i]] % MOD * inv[B[i] - free[i]] % MOD;
	}

	cout << ans << '\n';
}
