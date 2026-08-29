#include <bits/stdc++.h>

using namespace std;

using ll = double long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, a;
	while (1) {
		cin >> n >> a;

		if (n == 0 && a == 0) {
			break;
		}

		vector<ll> v(n);

		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		ll total_sum = accumulate(v.begin(), v.end(), 0LL);
		if (total_sum == a) {
			cout << ":D" << "\n";
			continue;
		}
		if (total_sum < a) {
			cout << "-.-" << "\n";
			continue;
		}

		ll l = 0;
		ll r = v[n - 1];
       for (int iter = 0; iter < 200; iter++) {
			ll mid = l + (r - l) / 2;

			auto up = upper_bound(v.begin(), v.end(), mid);

			ll idx = up - v.begin();

			ll area = accumulate(up, v.end(), 0.0L) - (mid * (n - idx));
			if (area < a) {
				r = mid;
			} else {
				l = mid;
			}
		}

       cout << fixed << setprecision(4) << l << "\n";
    }
}

