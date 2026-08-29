#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, size;
	size = 9;

    cin >> n;

    ll reserved = n;

    vector<ll> v(size), ans(size);

    for (ll i = 0; i < size; i++) {
        cin >> v[i];
    }

    auto min_it = min_element(v.begin(), v.end());
    ll min_pos = distance(v.begin(), min_it);

    ans[min_pos] = n / (*min_it);
    n = n % (*min_it);

    for (ll i = min_pos; i < size; i++) {
        if (ans[i] >= 1) {
            for (ll j = size - 1; j > i; j--) {
                while (ans[i] > 0 && v[j] <= v[i] + n) {
                    ans[j] += 1;
                    ans[i] -= 1;
                    n = v[i] + n - v[j];
                }
            }
        }
    }

    // Build as a string, cause the result can be very very large;
    // Because the formula is 10x + i, we just need to add i on the back of the string every iteration
    string s;
    s.reserve(reserved);
    for (ll i = size - 1; i >= 0; i--)
        for (ll k = 0; k < ans[i]; k++)
            s.push_back('0' + i + 1);

    cout << s << '\n';
}
