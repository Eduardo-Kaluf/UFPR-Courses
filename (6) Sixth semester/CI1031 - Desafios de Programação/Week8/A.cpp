#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll FER = MOD - 1;

ll power(ll b, ll e) {
	b %= MOD; ll r = 1;
	for (; e > 0; e >>= 1, b = b * b % MOD)
		if (e & 1) r = r * b % MOD;
	return r;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	ll cnt = 1;      // d(n) mod MOD
	ll c = 1;     // d(n) mod (MOD-1), usado como expoente
	ll sum = 1;
	ll prod = 1;

	for (int i = 0; i < n; ++i) {
		ll x, k;
		cin >> x >> k;

		// Total divisores
		// https://math.stackexchange.com/questions/433848/prime-factors-number-of-divisors
		// d = (e1 + 1) * (e2 + 1) * (e3 + 1) ...
		cnt = cnt * ((k + 1) % MOD) % MOD;

		// Soma geométrica
		// a1(q^n - 1) / q - 1
		ll num = (power(x, k + 1) - 1 + MOD) % MOD;
		ll inv = power(x - 1, MOD - 2);
		sum = sum * num % MOD * inv % MOD;

		// P' = P^(k+1) * (x^(k(k+1)/2))^c
		// Aqui já foi com Deus mesmo
		ll triangular = (k * (k + 1) / 2) % FER;
		prod = power(prod, (k + 1) % FER)
			 * power(power(x, triangular), c) % MOD;

		c = c * ((k + 1) % FER) % FER;
	}

	cout << cnt << ' ' << sum << ' ' << prod << '\n';
}
