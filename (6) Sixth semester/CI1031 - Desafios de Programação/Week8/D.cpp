#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#sieving-by-the-odd-numbers-only
	int n;
	cin >> n;

	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 3; i * i <= n; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}

	long long ans = 0;

	if (n < 4) {
		cout << 0;
		return 0;
	}

	if (n == 4) {
		cout << 1;
		return 0;
	}

	if (n % 2 == 1) {
		ans = is_prime[n - 2]; // Se o número é impar tem que somar com um primo par, ou seja, com 2
								 // Sendo assim n - 2 tem que ser primo para que seja possível somar N
	} else {
		for (int p = 3; p <= n / 2; p += 2)
            if (is_prime[p] && is_prime[n - p]) ++ans;
	}

	cout << ans << '\n';
}

