#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, s;

	cin >> n >> s;

	vector<ll> val;
	ll in;
	for (ll i = 0; i < n; i++) {
		cin >> in;
		val.push_back(in);
		if (in > s) {
			cout << 0;
			return 0;
		}
	}

	vector dp(n, vector(s + 1, 0));

	if (val[0] != 0) {
		dp[0][val[0]] = 1;
	}
	else {
		for (int v = 1; v <= s; v++) {
			dp[0][v] = 1;
		}
	}

	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j <= s; j++) {
			if (val[i] == 0 || val[i] == j) {
				ll score = dp[i - 1][j];

				if (j - 1 >= 1) {
					score = (score + dp[i - 1][j - 1]) % (1000000000 + 7);
				}

				if (j + 1 <= s) {
					score = (score + dp[i - 1][j + 1]) % (1000000000 + 7);
				}

				dp[i][j] = score % (1000000000 + 7);
			}
		}
	}

	ll ans = 0;
	for (ll j = 1; j <= s; j++) {
		ans = (ans + dp[n - 1][j]) % (1000000000 + 7);
	}

	cout << ans;
}
