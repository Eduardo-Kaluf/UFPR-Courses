#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> par, dsu_2ecc, dsu_cc, dsu_cc_size;
ll bridges;
ll lca_iteration;
vector<ll> last_visit;

void init(ll n) {
    par.resize(n);
    dsu_2ecc.resize(n);
    dsu_cc.resize(n);
    dsu_cc_size.resize(n);
    lca_iteration = 0;
    last_visit.assign(n, 0);
    for (ll i=0; i<n; ++i) {
        dsu_2ecc[i] = i;
        dsu_cc[i] = i;
        dsu_cc_size[i] = 1;
        par[i] = -1;
    }
    bridges = 0;
}

ll find_2ecc(ll v) {
    if (v == -1)
        return -1;
    return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
}

ll find_cc(ll v) {
    v = find_2ecc(v);
    return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
}

void make_root(ll v) {
    ll root = v;
    ll child = -1;
    while (v != -1) {
        ll p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v;
        v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_path (ll a, ll b) {
    ++lca_iteration;
    vector<ll> path_a, path_b;
    ll lca = -1;
    while (lca == -1) {
        if (a != -1) {
            a = find_2ecc(a);
            path_a.push_back(a);
            if (last_visit[a] == lca_iteration){
                lca = a;
                break;
                }
            last_visit[a] = lca_iteration;
            a = par[a];
        }
        if (b != -1) {
            b = find_2ecc(b);
            path_b.push_back(b);
            if (last_visit[b] == lca_iteration){
                lca = b;
                break;
                }
            last_visit[b] = lca_iteration;
            b = par[b];
        }

    }

    for (ll v : path_a) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
    for (ll v : path_b) {
        dsu_2ecc[v] = lca;
        if (v == lca)
            break;
        --bridges;
    }
}

void add_edge(ll a, ll b) {
    a = find_2ecc(a);
    b = find_2ecc(b);
    if (a == b)
        return;

    ll ca = find_cc(a);
    ll cb = find_cc(b);

    if (ca != cb) {
        ++bridges;
        if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
            swap(a, b);
            swap(ca, cb);
        }
        make_root(a);
        par[a] = dsu_cc[a] = b;
        dsu_cc_size[cb] += dsu_cc_size[a];
    } else {
        merge_path(a, b);
    }
}


// https://cp-algorithms.com/graph/bridge-searching-online.html
int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, m, x, y, z, source, target;
	cin >> n >> m;

    init(n + 1);

    vector<array<ll, 3>> edges(m);
	for (ll i = 0; i < m; i++) {
		cin >> x >> y >> z;
	    edges[i] = {x, y, z};
	    add_edge(x, y);
	}

	cin >> source >> target;

    vector<char> artifacts(n + 1, 0);
    vector<vector<pair<ll, ll>>> tree(n + 1);

    for (auto [x, y, z] : edges) {
        ll cx = find_2ecc(x);
        ll cy = find_2ecc(y);
        if (cx == cy) {
            if (z)
                artifacts[cx] = 1;
        } else {
            tree[cx].push_back({cy, z});
            tree[cy].push_back({cx, z});
        }
    }

    ll sourceT = find_2ecc(source);
    ll targetT = find_2ecc(target);

    vector<ll> couldGetArtifact(n + 1, -1);
    queue<ll> q;

    couldGetArtifact[sourceT] = artifacts[sourceT];

    q.push(sourceT);

    while (!q.empty()) {
        ll u = q.front();

        q.pop();

        for (auto [v, w] : tree[u]) {
            if (couldGetArtifact[v] == -1) {

                if (couldGetArtifact[u] || w || artifacts[v])
                    couldGetArtifact[v] = 1;
                else
                    couldGetArtifact[v] = 0;

                q.push(v);
            }
        }
    }

    string ans = "NO";
    if (couldGetArtifact[targetT])
        ans = "YES";

    cout << ans;
}
