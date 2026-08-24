#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll a, b, c, d, e, f;
	ll x, y, z, w, h, i, m;

	cin >> a >> b >> c >> d >> e >> f;

	if (d == 0) {
		cout << "Heric";	
		return 0;
	}

	if (c == 0) {
		cout << "Herbele";	
		return 0;
	}

	if (b == 0) {
		cout << "Heric";	
		return 0;
	}

	if (a == 0) {
		cout << "Herbele";	
		return 0;
	}

	if (e == 0) {
		cout << "Herbele";	
		return 0;
	}

	x = lcm(d, e);
	y = (x / d) * c;
	z = lcm(y, b);
	w = (z / b) * a;

    i = x * (z / y);
    h = (i / e) * f;

    if (h > w) {
        cout << "Herbele\n";
    }
    else {
        cout << "Heric\n";    
    }
    
    return 0;
}

