#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 200005;

struct Node {
	int zero, pos, neg;
};

Node t[4 * MAXN];

Node make(ll x) {
	return {x == 0, x > 0, x < 0};
}

Node combine(const Node& a, const Node& b) {
	return {a.zero + b.zero, a.pos + b.pos, a.neg + b.neg};
}

void build(const vector<ll>& a, int v, int tl, int tr) {
	if (tr - tl == 1) {
		t[v] = make(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void set_tree(int v, int tl, int tr, int pos, ll val) {
	if (tr - tl == 1)
		t[v] = make(val);
	else {
		int tm = (tl + tr) / 2;

		if (pos < tm)
			set_tree(v*2, tl, tm, pos, val);
		else
			set_tree(v*2+1, tm, tr, pos, val);

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return {0, 0, 0};
	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) / 2;

	return combine(query(v*2, tl, tm, l, r), query(v*2+1, tm, tr, l, r));
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, k;

	cin >> n >> k;

	vector<ll> vec(n);
	for (ll i = 0; i < n; i++)
		cin >> vec[i];

	build(vec, 1, 0, n);

	char id;
	ll I, Y, J;
	for (ll i = 0; i < k; i++) {
		cin >> id;

		if (id == 'A') {
			cin >> I >> Y;
			set_tree(1, 0, n, I - 1, Y);
		}
		else {
			cin >> I >> J;
			Node no = query(1, 0, n, I - 1, J);

			if (no.zero > 0)
				cout << 0;
			else if (no.neg % 2)
				cout << "-";
			else
				cout << "+";
		}
	}

	cout << "\n";
}

