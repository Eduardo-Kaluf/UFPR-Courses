#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, a, b, c, xa, xb, xc, max_val;

	cin >> t;

	while(t--) {
		cin >> a >> b >> c;

		max_val = 0;

		for (ll i = 0; i <= 5; i++) {
			for (ll j = 0; j <= 5 - i; j++) {
				xa = a + i;
				xb = b + j;
				xc = c + 5 - i - j;

				max_val = max(max_val, xa * xb * xc);
			}
		}

		cout << max_val << "\n";
	}
}

