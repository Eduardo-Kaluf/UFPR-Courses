#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<long long> primes;

ll MAX = 1e5 + 1500;

ll binarySearch(ll n_target, int k) {
	int low = 0;
	int high = primes.size() - k;
	ll ans = 0;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		ll prod = 1;
		bool fits = true;
		for (int j = mid; j < mid + k; j++) {
			if (prod > n_target / primes[j]) {
				fits = false;
				break;
			}
			prod *= primes[j];
		}

		if (fits) {
			ans = prod;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return ans;
}

void sieve() {
	vector is_prime(MAX + 15, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= MAX; ++i)
		if (is_prime[i])
			for (ll j = i * i; j <= MAX; j += i)
				is_prime[j] = false;
	for (ll i = 2; i <= MAX; ++i)
		if (is_prime[i]) primes.push_back(i);
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, n, k;

	cin >> t;

	sieve();

	while (t--) {
		cin >> n >> k;

		cout << binarySearch(n, k) << "\n";
	}
}

