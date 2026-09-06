#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k, c;

    cin >> n >> k >> c;
    vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    ll points = accumulate(vec.begin(), vec.end(), 0);

    vector<ll> prefixSum(n + 1, 0);
    prefixSum[0] = 0;
    for (ll i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + vec[i];

    vector<ll> current(n + 1, 0);
    vector<ll> prev(n + 1, 0);

    for (ll i = 0; i <= n; i++)
        prev[i] = 0;

    for (ll i = 1; i <= k; i++) {
        fill(current.begin(), current.end(), 987654321);

        for (ll j = n - 1; j >= 0; j--) {
            current[j] = current[j + 1];

            if (c + j <= n) {
                current[j] = min(current[j], prefixSum[j + c] - prefixSum[j] + prev[j + c]);
            }
        }
        prev = current;
    }

    cout << points - current[0];
}