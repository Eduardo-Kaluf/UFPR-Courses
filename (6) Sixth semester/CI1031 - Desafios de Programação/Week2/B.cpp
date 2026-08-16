#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, n, m, h;
	pair<ll, ll> p;

	cin >> t;
	
	
	for (ll i = 0; i < t; i++) {
		cin >> n >> m >> h;
		
		unordered_map<ll, ll> li, diff;
		
		for (ll j = 0; j < n; j++) {
			cin >> li[j];
		}

		for (ll k = 0; k < m; k++) {
			cin >> p.first >> p.second;
			
			if (diff[p.first - 1] + li[p.first - 1] + p.second > h) {
				diff.clear();
				continue;
			}
		
			diff[p.first - 1] += p.second;
		}
	
		for (ll l = 0; l < n; l++) {
			cout << diff[l] + li[l] << " ";
		}
	
		cout << "\n";
	}
}

