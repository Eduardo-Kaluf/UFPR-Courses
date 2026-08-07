#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, n;

	cin >> t;

	while (t--) {
		cin >> n;

		if (n == 1)
			cout << 1;
		else if (n == 2)
			cout << -1;
		else {
			cout << "1 2 3 ";
			ll temp = 6;
			for (int i = 0; i < n - 3; i++) {
				cout << temp << " ";
			  temp = temp * 2;
			}
		}

		cout << "\n";
	}
}
