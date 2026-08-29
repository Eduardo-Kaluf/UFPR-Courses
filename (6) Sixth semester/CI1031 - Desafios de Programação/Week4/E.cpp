#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, x, diff_1, diff_2;

	vector<ll> v(3);

	cin >> t;

	while (t--) {
		cin >> v[0] >> v[1] >> v[2] >> x;

		sort(v.begin(), v.end());

		diff_1 = v[1] - v[0];
		if (x > diff_1) {
			v[0] += diff_1;
			x -= diff_1;
		} else {
			cout << (v[0] + x) * v[1] * v[2] << "\n";
			continue;
		}

		diff_2 = v[2] - v[1];
		if (x > 2 * diff_2) {
			v[0] += diff_2;
			v[1] += diff_2;
			x -= 2 * diff_2;
		} else {
			cout << (v[0] + x / 2) * (v[1] + (x / 2) + (x % 2)) * v[2] << "\n";
			continue;
		}

		if (x % 3 == 1) {
			v[0] += 1;
		}
		if (x % 3 == 2) {
			v[0] += 1;
			v[1] += 1;
		}

		cout << (v[0] + (x / 3)) * (v[1] + (x / 3)) * (v[2] + (x / 3)) << "\n";
	}
}

