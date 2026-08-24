#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
    cin.tie(0)->sync_with_stdio(0);
        
    string input_s;
    ll split1, split2, max_val;

    cin >> input_s;

	sort(input_s.begin(), input_s.end());

    max_val = 0;
    do {
    	for (ll i = 1; i < input_s.size(); i++) {

    		split1 = stoll(input_s.substr(0, i)); 
			split2 = stoll(input_s.substr(i));

			if (split1 * split2 > max_val) {
				max_val = split1 * split2;
			} 
    	}
    }
    while (next_permutation(input_s.begin(), input_s.end()));

    cout << max_val;
}