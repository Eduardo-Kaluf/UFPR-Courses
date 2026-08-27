#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// https://www.geeksforgeeks.org/dsa/fast-exponention-using-bit-manipulation/
// Adapted
ll powerOptimised(ll a, ll n, ll cap) {
	if (n == 0) 
		return 1;

	if (a == 0) 
		return 0;

    ll ans = 1;

    while (n > 0) {
        if (n & 1) {
            if (ans > cap / a) return cap; 
            ans = ans * a;
        }

        n >>= 1;

        if (n) {
            if (a > cap / a) a = cap;
            else a = a * a;
        }
    }

    return ans;
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k, l, r, val;
	val = 1;

	cin >> n >> k;

	l = 1;
	r = n;

    while (l < r) {
        ll mid = l + (r - l) / (ll) 2;
        
        if (powerOptimised(mid, k, n) >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    val = l;

    l = 0; 
    r = k;
    
    while (l < r) {
        ll mid = l + (r - l) / (ll) 2;
        
        __int128 mult = (__int128) powerOptimised(val - 1, k - mid, n) * powerOptimised(val, mid, n);
        if (mult >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

	cout << ((val - 1) * (k - l)) + (val * l);
}
