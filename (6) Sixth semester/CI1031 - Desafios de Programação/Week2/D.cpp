#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k, item;

	stack<pair<ll, ll>> st;

	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> k;
	
		while (!st.empty()) {
			if (st.top().first < k) {
				cout << st.top().second << " ";
				break;
			}
		
			st.pop();
		}

		if (st.empty()) {
			cout << "0 ";
		}

		st.push({k, i});
	}
}
