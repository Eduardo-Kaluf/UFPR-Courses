#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, f, s, count, last_init;

	vector<pair<ll, ll>> v;

	cin >> n;

	for (ll i = 0; i < n; i++) {
		cin >> f >> s;
		v.push_back({s, f});
	}

	sort(v.begin(), v.end());

	count = 1;
	last_init = v[0].first;
	for (ll i = 1; i < n; i++) {
		if (v[i].second >= last_init) {
			last_init = v[i].first;
			count++;
		}
	}

	cout << count;
}
