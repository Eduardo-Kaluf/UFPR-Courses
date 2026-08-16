#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);


	ll n, max = 0, l = 0;
	cin >> n;
	set<ll> s;
	
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];	
	}

	for (int r = 0; r < n; r++) {
		while (s.contains(v[r])) {
			s.erase(v[l]);
			l++;
		}
		
		s.insert(v[r]);

		if (r - l + 1 > max) {
			max = r - l + 1;
		}
			
	}
	
	cout << max;
}

