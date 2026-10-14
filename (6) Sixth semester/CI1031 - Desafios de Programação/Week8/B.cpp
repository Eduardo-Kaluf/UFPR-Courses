#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll t[4 * 100005];

void t_build(const vector<ll>& a, ll v, ll tl, ll tr) {
	if (tr - tl == 1) {
		t[v] = 1;
	} else {
		ll tm = (tl + tr) / 2;
		t_build(a, v*2, tl, tm);
		t_build(a, v*2+1, tm, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void t_remove(ll v, ll tl, ll tr, ll pos) {
	if (tr - tl == 1)
		t[v] = 0;
	else {
		ll tm = (tl + tr) / 2;

		if (pos < tm)
			t_remove(v*2, tl, tm, pos);
		else
			t_remove(v*2+1, tm, tr, pos);

		t[v] = t[v*2] + t[v*2+1];
	}
}

ll t_find(ll v, ll tl, ll tr, ll k) {
	if (tr - tl == 1)
		return tl;
	ll tm = (tl + tr) / 2;

	if (k < t[v*2])
		return t_find(v*2, tl, tm, k);

	return t_find(v*2+1, tm, tr, k - t[v*2]);
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	t_build(a, 1, 0, n);

	char id;
	ll offset = 0;
	ll move;
	for (int i = 0; i < q; i++) {
		cin >> id;

		if (id == 'q') {
			cout << a[t_find(1, 0, n, offset)] << '\n';
		}
		else if (id == 'm') {
			cin >> move;
			offset += move;
		}
		else {
			t_remove(1, 0, n, t_find(1, 0, n, offset));
		}
	}
}

