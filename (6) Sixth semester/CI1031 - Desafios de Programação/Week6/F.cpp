#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct node {
	int id;
	int burnCount;
	ll burnTime;
	ll x;
	ll y;
};

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, t;
	cin >> n >> m >> t;

	vector<node> pool(n * m);
	vector florest(n, vector<node*>(m));
	vector<node*> q;
	q.reserve(n * m);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			int id;
			cin >> id;

			florest[i][j] = &pool[i * m + j];
			*florest[i][j] = node{id, 0, -1, i, j};

			if (florest[i][j]->id == 0) {
				florest[i][j]->burnTime = 0;
				q.push_back(florest[i][j]);
			}
		}
	}

	for (size_t h = 0; h < q.size(); h++) {
		node* v = q[h];
		ll parity = 0;
		for (ll i = v->x - 1; i <= v->x + 1; i++) {
			for (ll j = v->y - 1; j <= v->y + 1; j++) {
				parity = !parity;
				if (i >= 0 && i < n && j >= 0 && j < m && (i != v->x || j != v->y)) {
					ll itBurnTime = florest[i][j]->burnTime;
					ll itId = florest[i][j]->id;

					if (parity) {
						if (itId == 1 && itBurnTime == -1) {
							florest[i][j]->burnTime = v->burnTime + 1;
							q.push_back(florest[i][j]);
						}
						continue;
					}

					if (itId == 1 && itBurnTime == -1) {
						florest[i][j]->burnTime = v->burnTime + 1;
						q.push_back(florest[i][j]);
						continue;
					}
					if (itId == 2 && itBurnTime == -1) {
						florest[i][j]->burnTime = v->burnTime + 1;
						q.push_back(florest[i][j]);
						continue;
					}
					if (itId == 3 && itBurnTime == -1) {
						florest[i][j]->burnCount += 1;
						if (florest[i][j]->burnCount >= 2) {
							florest[i][j]->burnTime = v->burnTime + 1;
							q.push_back(florest[i][j]);
						}
						continue;
					}
					if (itId == 4 && itBurnTime == -1) {
						florest[i][j]->burnCount += 1;
						if (florest[i][j]->burnCount >= 3) {
							florest[i][j]->burnTime = v->burnTime + 1;
							q.push_back(florest[i][j]);
						}
					}
				}
			}
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (florest[i][j]->burnTime != -1 && florest[i][j]->burnTime <= t) {
				ans++;
			}
		}
	}

	cout << ans;
}

