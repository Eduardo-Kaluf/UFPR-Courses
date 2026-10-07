#include <bits/stdc++.h>

using namespace std;

using ll = long long;


class DSU {
private:
    vector<ll> p;  // parent if positive, size if negative, parent of root is the size of component

public:
    ll comps;
    DSU(ll N) {
        comps = N;
        p = vector<ll>(N, -1);
    }

    ll root(ll x) {
        if (p[x] < 0) {
            return x;
        }

        return p[x] = root(p[x]); // path compression (keep tree height under 2)
    }

    bool sameSet(ll a, ll b) {
        return root(a) == root(b);
    }

    void unite(ll a, ll b) {
        a = root(a), b = root(b);

        if (a == b) {
            return;
        }

        if (p[a] > p[b]) { // small to large merging
            swap(a, b);
        }

        p[a] += p[b];
        p[b] = a;

        comps -= 1;

        return;
    }

    ll size(ll x) {
        return -p[root(x)];
    }
};


int main () {
	cin.tie(0)->sync_with_stdio(0);

    ll n, m, k, u, v;

	cin >> n >> m >> k;

    DSU dsu(n + 1);
    map<pair<ll, ll>, ll> maps;
    stack<pair<ll, ll>> st;


	for (ll i = 0; i < m; i++) {
	    cin >> u >> v;
        maps[{u, v}] = 2;
	}

    for (ll i = 0; i < k; i++) {
	    cin >> u >> v;
        maps[{u, v}] = 1;
        st.push({u, v});
    }

    for (auto& [k, v] : maps)
        if (v > 1)
            dsu.unite(k.first, k.second);

    vector<ll> ans(k);
    for (ll i = 0; i < k; i++) {
        ans[i] = dsu.comps;
        pair<ll, ll> p = st.top();
        st.pop();
        dsu.unite(p.first, p.second);
    }

    for (ll i = k - 1; i >= 0; i--) {
        cout << ans[i] - 1 << " ";
    }
}

