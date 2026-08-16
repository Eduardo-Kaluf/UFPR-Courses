#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool cmp(const pair<string, pair<ll, ll>>& a, const pair<string, pair<ll, ll>>& b) {
	if (a.second.first != b.second.first) {
		return a.second.first > b.second.first;
    	}

	if (a.second.second != b.second.second) {
		return a.second.second < b.second.second;
	}
	
	return a.first < b.first; 
}


int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, balloon, time;

	string name;

	map<string, pair<ll, ll>> mp;

	cin >> n;

	for (ll i = 0; i < n; i++) {
		cin >> name;
		
		mp[name] = {0, 0};
	}

	cin >> m;

	for (ll i = 0; i < m; i++) {
		cin >> name >> balloon >> time;

		mp[name].first += balloon;
		mp[name].second += time;
	}

	// https://stackoverflow.com/a/60098594
	vector<pair<string, pair<ll, ll>>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);


        for (ll i = 0; i < n; i++) {
		cout << v[i].first << "\n";
    	}
}

