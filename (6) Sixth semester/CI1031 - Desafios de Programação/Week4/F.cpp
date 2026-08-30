#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// https://cp-algorithms.com/data_structures/segment_tree.html#construction
// https://www.geeksforgeeks.org/dsa/prefix-sum-array-implementation-applications-competitive-programming/
// https://www.youtube.com/watch?v=N_AgTyMHgtw
int main () {
	cin.tie(0)->sync_with_stdio(0);

     ll n, k;

     cin >> n >> k;
     ll a[n];
     map<ll, ll> mp;


     for (ll i = 0; i < n; i++) {
          cin >> a[i];
     }

    mp[0] = 1;
    ll s = 0;
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        s += a[i];
        total += mp[s - k];
        mp[s] += 1;
    }

    cout << total << "\n";
}

