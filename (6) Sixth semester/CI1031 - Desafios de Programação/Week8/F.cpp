#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto fraction(ll p, ll q) {
	vector<ll> a;
	while(q) {
		a.push_back(p / q);
		tie(p, q) = make_pair(q, p % q);
	}
	return a;
}

// https://cp-algorithms.com/algebra/continued-fractions.html#implementation
int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, n, d;
	cin >> t;

	while (t--) {
		cin >> n >> d;

		auto ans = fraction(n, d);

		if (ans.size() == 1) {
			cout << "[" << ans[0] << "]\n";
			continue;
		}

		cout << "[" << ans[0] << ";";

		for (int i = 1; i < ans.size() - 1; i++) {
			cout << ans[i] << ',';
		}

		cout << ans[ans.size() - 1] << "]\n";
	}
}

