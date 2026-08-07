#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, min, x, y;
	min = 0;

	cin >> n;

	if (n == 1) {
		cout << min;
		return 0;
	}

	cin >> x;
	n--;

	while (n--) {
		cin >> y;

		if (y < x) {
			min += x - y;
			y = x;
		}

		x = y;
	}

	cout << min;
}
