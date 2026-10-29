#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ans = 0;

void is_bridge(ll v, ll to) {
    ans++;
}

ll n; // number of nodes
vector<vector<ll>> adj; // adjacency list of graph

vector<bool> visited;
vector<ll> tin, low;
ll timer;

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (ll to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                is_bridge(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (ll i = 1; i < n + 1; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main () {
    cin.tie(0)->sync_with_stdio(0);

    ll t, m, x, y;

    cin >> t;

    while(t--) {
        cin >> n >> m;

        adj.assign(n + 1, {});

        for (ll i = 0; i < m; i++) {
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        ans = 0;
        find_bridges();

        cout << ans << "\n";
    }
}
