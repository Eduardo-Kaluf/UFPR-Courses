#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

vector<ll> cuts(15);

vector<char> segmented_sieve(long long L, long long R) {
	// generate all primes up to sqrt(R)
	vector<char> mark(R + 1, true);
	vector<long long> nums;
	for (auto i : cuts) {
		for (long long j = i; j <= R; j += i)
			mark[j] = true;
	}
	for (int i = 0; i <= R; ++i)
		if (!mark[i])
			nums.push_back(i);

	vector<char> is_kalimos(R - L + 1, true);
	for (long long i : nums)
		for (long long j = max(i, (L + i - 1) / i); j <= R; j += i)
			is_kalimos[j - L] = false;
	for (long long x = L; x <= min(R, 1LL); x++)
		is_kalimos[x - L] = false;
	return is_kalimos;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll a, b, n;
	cin >> a >> b >> n;

	vector<ll> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	ull ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll l = 1;
		// Calcula mmc do subconjunto dos crivos
		for (int i = 0; i < n && l <= b; i++) {
			if (mask >> i & 1) {
				ll y = x[i] / __gcd(l, x[i]);

				l = (l > b / y) ? b + 1 : l * y;
			}
		}

		// se passou nao soma nada
		if (l > b)
			continue;

		// quantia de multiplos
		ull cnt = b / l - (a - 1) / l;

		// sinal inclusão/exclusão
		if (__builtin_popcount(mask) % 2)
			ans -= cnt;
		else
			ans += cnt;
	}

	cout << ans << '\n';
}
