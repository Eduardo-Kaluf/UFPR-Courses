#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);
	ll n, remainder;

	cin >> n;

	n = n - 3;
	remainder = n % 4;

	cout << "ROY";

	for (ll i = 0; i < n / 4; i++)
		cout << "GBIV";

	if (remainder == 1)
		cout << "G";
	if (remainder == 2)
		cout << "GB";
	if (remainder == 3)
		cout << "GBI";
}
