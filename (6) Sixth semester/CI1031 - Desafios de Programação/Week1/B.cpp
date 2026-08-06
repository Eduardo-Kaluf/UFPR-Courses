#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

    ll n, q, k;
    ll l, r;

    cin >> n >> q >> k;
    while(q--) {
        cin >> l >> r;

        if (k >= l && k <= r)
            k = n - (r - k);
        else if (k < l)
            continue;
        else if (k > r)
            k = k - (r - l + 1);
    }

    cout << k;
}

