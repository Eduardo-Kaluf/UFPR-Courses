#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, u, v;

    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);

    vector<bool> isSource(n + 1, 1);

    for (ll i = 0; i < m; i++) {
        cin >> u >> v;

        adj[u].push_back(v);

        isSource[v] = false;
    }

    // If this one finds two sources that reaches it, then we can already count one on the answer
    vector<array<ll, 2>> msgReachedFromSource(n + 1, {0, 0});

    queue<pair<ll, ll>> q;

    for (ll i = 1; i <= n; i++) {
        if (isSource[i]) {
            msgReachedFromSource[i][0] = i;
            q.push({i, i});
        }
    }

    while (!q.empty()) {
        auto [node, sourceId] = q.front();

        q.pop();

        for (ll v : adj[node]) {
            auto &cur = msgReachedFromSource[v];

            if (cur[0] == sourceId || cur[1] == sourceId)
                continue;

            if (cur[0] == 0)
                cur[0] = sourceId;
            else if (cur[1] == 0)
                cur[1] = sourceId;
            else
                continue;

            q.push({v, sourceId}); // Continues to see if we find any more nodes
        }
    }

    ll ans = 0;
    for (auto msg : msgReachedFromSource)
        if (msg[1] != 0)
            ans += 1;

    cout << ans;
}
