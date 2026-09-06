#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll func(ll n, map<ll, ll> &ans) {
    if (ans[n] != 0) {
        return ans[n];
    }

    ans[n] = func(n / 2, ans) + func(n / 3, ans);

    return ans[n];
}



int main () {
	cin.tie(0)->sync_with_stdio(0);

    ll n;

    cin >> n;

    map<ll, ll> ans;

    ans[0] = 1;

    cout << func(n, ans);
}

