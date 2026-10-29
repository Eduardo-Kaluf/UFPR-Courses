#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> st;    // - stack holding the unclaimed vertices
vector<ll> roots; // - keeps track of the SCC roots of the vertices
ll timer;         // - dfs timestamp counter
vector<ll> t_in;  // - keeps track of the dfs timestamp of the vertices
vector<ll> t_low; // - keeps track of the lowest t_in of unclaimed vertices
                  // reachable in the subtree

// implements the tarjan algorithm for strongly connected components
void dfs(ll v, vector<vector<ll>> const &adj, vector<vector<ll>> &components) {

    t_low[v] = t_in[v] = timer++;
    st.push_back(v);

    for (auto u : adj[v]) {
        if (t_in[u] == -1) { // tree-edge
            dfs(u, adj, components);
            t_low[v] = min(t_low[v], t_low[u]);
        } else if (roots[u] == -1) { // back-edge, cross-edge or forward-edge to an unclaimed vertex
            t_low[v] = min(t_low[v], t_in[u]);
        }
    }

    if (t_low[v] == t_in[v]) { // vertex is a root
        components.push_back({v}); // initializes a new component with root v
        while (true) {
            ll u = st.back();
            st.pop_back();
            roots[u] = v; // claims the vertex
            if (u == v)
                break;
            components.back().push_back(u); // adds vertex u to the component of v
        }
    }
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components(vector<vector<ll>> const &adj,
                                   vector<vector<ll>> &components,
                                   vector<vector<ll>> &adj_cond) {
    components.clear();
    adj_cond.clear();

    ll n = adj.size();

    st.clear();
    roots.assign(n, -1);
    timer = 0;
    t_in.assign(n, -1);
    t_low.assign(n, -1);

    // applies the tarjan algorithm to all the vertices
    // adds vertices to the components in reverse topological order
    for (ll v = 0; v < n; v++) {
        if (t_in[v] == -1) {
            dfs(v, adj, components);
        }
    }

    // adds edges to the condensation graph
    adj_cond.assign(n, {});
    for (ll v = 0; v < n; v++) {
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
    }
}

//https://cp-algorithms.com/graph/strongly-connected-components.html#building-the-condensation-graph
int main () {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, r, s;
    vector<vector<ll>> adj;

    cin >> n >> m;
    adj.assign(n + 1, {});

    for (ll i = 0; i < m; i++) {
        cin >> r >> s;
        adj[r].push_back(s);
    }

    vector<vector<ll>> components;
    vector<vector<ll>> adj_cond;

    strongly_connected_components(adj, components, adj_cond);

    vector<ll> in(n + 1, 0), out(n + 1, 0);
    for (ll u = 1; u <= n; u++)
        for (ll v : adj_cond[u]) { out[u]++; in[v]++; }

    ll counter = 0, sources = 0, sinks = 0;
    for (ll i = 1; i <= n; i++) {
        if (roots[i] != i)
            continue;

        counter++;

        if (in[i] == 0)
            sources++;

        if (out[i] == 0)
            sinks++;
    }

    ll ans = 0;
    if (counter != 1)
        ans = max(sources, sinks);

    cout << ans;
}