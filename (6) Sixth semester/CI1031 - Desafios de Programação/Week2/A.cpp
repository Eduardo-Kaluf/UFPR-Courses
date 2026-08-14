#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);
    
    multiset<ll> ms;
    
    ll n, k, parity;

    cin >> n >> k;
    
    ms.insert(k);

    multiset<ll>::iterator it = ms.begin();

    cout << *it << "\n";
   
    for (int i = 1; i < n; i++) {
        cin >> k;

        ms.insert(k);

        parity = i % 2;

        if (parity == 0) {
            if (k >= *it) {
                it++;
            }
        }
        else if (k < *it) {
            it--;
        }

        cout << *it << "\n";
    }
}

