#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll inf = 987654321;
int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll q, c, n;
	cin >> q >> n;

	vector<ll> len(n);
	for (ll i = 0; i < n; i++) {
		cin >> len[i];
	}

	sort(len.begin(), len.end());

	vector<ll> v(10e5);
	vector<ll> s(10e5);

	for (ll i = 0; i < 100000; i++) {
		v[i] = inf;
		s[i] = inf;
	}

	v[0] = 0;
	for (ll i = 1; i <= 100000; i++) {
		for (ll j = n - 1; j >= 0; j--) {
			if (i >= len[j] && v[i - len[j]] != inf) {
				if (v[i - len[j]] + 1 < v[i]) {
					v[i] = v[i - len[j]] + 1;
					s[i] = len[j];
				}
			}
		}
	}

	while (q--) {
		cin >> c;

		if (v[c] == inf) {
			cout << "NAO" << "\n";
		}
		else {
			while (c > 0) {
				cout << s[c] << " ";

				c -= s[c];
			}
			cout << "\n";
		}
	}
}

