#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll t[4 * 100015];
ll lazy_add[4 * 100015];
ll lazy_set[4 * 100015];
bool assigned[4 * 100015];


void build(ll a[], ll v, ll tl, ll tr) {
    if (tr - tl == 1) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void push_sum(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (r <= tl || tr <= l) 
        return;
    if (l <= tl && tr <= r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push_sum(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, r, addend);
        update(v*2+1, tm, tr, l, r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void push(ll v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void assign(ll v, ll tl, ll tr, ll l, ll r, ll new_val) {
    if (r <= tl || tr <= l) 
        return;
    if (l <= tl && tr <= r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        assign(v*2, tl, tm, l, r, new_val);
        assign(v*2+1, tm, tr, l, r, new_val);
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (r <= tl || tr <= l) return 0;  // no overlap
    if (l <= tl && tr <= r) return t[v];  // nested segment

    ll tm = (tl + tr) / 2;
    // partial overlap
    return sum(v * 2, tl, tm, l, r)
            + sum(v * 2 + 1, tm, tr, l, r);
}


int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, q;
	cin >> n >> q;

	vector<ll> vec(n);
	for (ll i = 0; i < n; i++)
		cin >> vec[i];

	build(vec, 1, 0, n);

	ll id, a, b, x;
	for (ll i = 0; i < q; i++) {
		cin >> id >> a >> b;

		if (id == 1) {
			cin >> x;
			update(1, 0, n, a, b, x);	
		}
		else if (id == 2) {
			cin >> x;
			assign(1, 0, n, a, b, x);
		}
		else {
			sum(1, 0, n, a, b);
		}
	}


}

