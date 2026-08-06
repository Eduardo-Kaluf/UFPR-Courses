#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll t, n, x;
	cin >> t;

	while(t--) {
        cin >> n;

        vector<bool> v(n, 0);

        while(n--) {
            cin >> x;
            v[x - 1] = 1;
        }

        cout << accumulate(v.begin(), v.end(), 0) << "\n";
    }
}

