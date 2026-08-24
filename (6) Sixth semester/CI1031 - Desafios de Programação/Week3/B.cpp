#include <bits/stdc++.h>

using namespace std;

using ll = long long;


ll rec(string in, ll prev) {
	ll rec_sum = 0;

	if (in.size() == 1) {
		return 0;
	}

	for (ll i = 1; i < in.size(); i++) {
		rec_sum += stoll(in.substr(0, i)) + stoll(in.substr(i)) + prev + rec(in.substr(i), stoll(in.substr(0, i)) + prev);
	}

	return rec_sum;
}



int main () {
	cin.tie(0)->sync_with_stdio(0);

	string p;

	cin >> p;

	cout << rec(p, 0) + stoll(p);
}
