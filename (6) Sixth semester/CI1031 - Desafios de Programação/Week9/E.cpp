#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 987654231;
struct Node {
	int sum, pre;
};

Node t[4 * 200005];

Node combine(const Node& a, const Node& b) {
	return {a.sum + b.sum, min(a.pre, a.sum + b.pre)};
}

Node assign(char x) {
	if (x == '(')
		return {1, 1};

	return {-1, -1};
}

void build(const vector<char>& a, int v, int tl, int tr) {
	if (tr - tl == 1) {
		t[v] = assign(a[tl]);
	} else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void set_tree(int v, int tl, int tr, int pos, char val) {
	if (tr - tl == 1)
		t[v] = assign(val);
	else {
		int tm = (tl + tr) / 2;

		if (pos < tm)
			set_tree(v*2, tl, tm, pos, val);
		else
			set_tree(v*2+1, tm, tr, pos, val);

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node sum(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l) return {0, INF}; // no overlap
	if (l <= tl && tr <= r) return t[v];  // nested segment

	int tm = (tl + tr) / 2;
	// partial overlap
	return combine(sum(v * 2, tl, tm, l, r), sum(v * 2 + 1, tm, tr, l, r));
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, q;
	cin >> n >> q;

	vector<char> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	build(v, 1, 0, n);

	ll t, a, b;
	for (int i = 0; i < q; i++) {
		cin >> t;

		if (t == 1) {
			cin >> a >> b;
			a -= 1;
			b -= 1;
			swap(v[a], v[b]);
			set_tree(1, 0, n, a, v[a]);
			set_tree(1, 0, n, b, v[b]);
		}
		else {
			cin >> a >> b;
			a -= 1;
			Node val = sum(1, 0, n, a, b);

			if (val.sum == 0 && val.pre >= 0)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}

