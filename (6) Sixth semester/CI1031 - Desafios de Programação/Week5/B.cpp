#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll inf = 987654321;
int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k, h, p;
	cin >> n >> k;

	vector<ll> houseDistances(n + 1);
	vector<ll> housePrefixes(n + 1);
	housePrefixes[0] = 0;
	houseDistances[0] = 0;
	housePrefixes[1] = 0;
	houseDistances[1] = 0;
	for (ll i = 2; i < n + 1; i++) {
		cin >> houseDistances[i];
		housePrefixes[i] = housePrefixes[i - 1] + houseDistances[i];
	}

	vector<ll> playesPoints(n + 1, 0);
	while (k--) {
		cin >> h >> p;

		vector<ll> players(p + 1);
		for (int i = 1 ; i < p + 1; i++) {
			cin >> players[i];
		}

		sort(players.begin(), players.end());

		ll max_val = -inf;
		ll position = -inf;
		for (int i = 1; i < p + 1; i++) {
			if (abs(housePrefixes[h] - housePrefixes[players[i]]) > max_val) {
				max_val = abs(housePrefixes[h] - housePrefixes[players[i]]);
				position = players[i];
			}
		}

		if (position != -inf) {
			playesPoints[position] += 1;
		}
	}

	auto max_it = max_element(playesPoints.begin(), playesPoints.end());

	auto first_index = distance(playesPoints.begin(), max_it);
	cout << first_index;
}

