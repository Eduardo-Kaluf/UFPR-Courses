#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 3250 é mais ou menos raiz de 1e7

ll power(ll b, ll e) {
	ll r = 1;
	for (; e > 0; e >>= 1, b = b * b)
		if (e & 1) r = r * b;
	return r;
}

vector<long long> primes;

void sieve() {
	vector is_prime(3250 + 15, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= 3250; ++i)
		if (is_prime[i])
			for (int j = i * i; j <= 3250; j += i)
				is_prime[j] = false;
	for (int i = 2; i <= 3250; ++i)
		if (is_prime[i]) primes.push_back(i);
}

vector<long long> trial_division4(long long n) {
	vector<long long> factorization;
	for (long long d : primes) {
		if (d * d > n)
			break;
		while (n % d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, k, x, e;

	cin >> t;

	sieve();

	while (t--) {
		cin >> k;
		ll num = 1;
		for (int i = 0; i < k; i++) {
			cin >> x >> e;
			num *= power(x, e);
		}

		vector<long long> ans = trial_division4(num - 1);
		vector<pair<ll,int>> out;
		for (ll p : ans)
			if (!out.empty() && out.back().first == p)
				out.back().second++;
			else
				out.push_back({p, 1});

		reverse(out.begin(), out.end());

		for (auto  p : out)
			cout << p.first << ' ' << p.second << '\n';
	}
}

