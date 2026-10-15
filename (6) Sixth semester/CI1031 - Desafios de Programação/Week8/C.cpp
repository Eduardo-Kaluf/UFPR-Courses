#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll sum_t[4 * 200015],
add_t[4 * 200015],
set_t[4 * 200015];
bool marked[4 * 200015];

void apply_set(ll v, ll tl, ll tr, ll x) {
    sum_t[v] = x * (tr - tl); // Valor do llervalo lleiro é o número de elementos vezes valor settado
    set_t[v] = x; // Elementos settados para x
    marked[v] = true; // Marca que ocorreu set para lazy
    add_t[v] = 0; // Add é zero pois set sobreescreve
}

void apply_add(ll v, ll tl, ll tr, ll x) {
    sum_t[v] += x * (tr - tl); // Valor do llervalo lleiro é o número de elementos vezes valor settado

    // Se está com flag do set soma no set, se não soma na adição
    if (marked[v])
        set_t[v] += x;
    else
        add_t[v] += x;
}

// REaliza as duas operações de acordo com as "flags"
void push(ll v, ll tl, ll tr) {
    ll tm = (tl + tr) / 2;

    if (marked[v]) {
        apply_set(2*v, tl, tm, set_t[v]);
        apply_set(2*v+1, tm, tr, set_t[v]);
        marked[v] = false;
    }

    if (add_t[v]) {
        apply_add(2*v, tl, tm, add_t[v]);
        apply_add(2*v+1, tm, tr, add_t[v]);
        add_t[v] = 0;
    }
}

// Build padrão do site https://cp-algorithms.com/data_structures/segment_tree.html
void build(const vector<ll>& a, ll v, ll tl, ll tr) {
    if (tr - tl == 1) {
        sum_t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm, tr);
        sum_t[v] = sum_t[2*v] + sum_t[2*v+1];
    }
}

// Update padrão do lazy
// Flag identifica o que realizar de operação
// Faz tanto o push quanto sobe somando os valores (assignment and addition)
void update(ll type, ll v, ll tl, ll tr, ll l, ll r, ll x) {
    if (r <= tl || tr <= l)
        return;
    if (l <= tl && tr <= r) {
        if (type == 1)
            apply_add(v, tl, tr, x);
        else
            apply_set(v, tl, tr, x);
        return;
    }
    push(v, tl, tr);

    ll tm = (tl + tr) / 2;

    update(type, 2*v, tl, tm, l, r, x);
    update(type, 2*v+1, tm, tr, l, r, x);

    sum_t[v] = sum_t[2*v] + sum_t[2*v+1];
}

// Query padrão https://cp-algorithms.com/data_structures/segment_tree.html
ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (r <= tl || tr <= l)
        return 0;
    if (l <= tl && tr <= r)
        return sum_t[v];

    push(v, tl, tr);

    ll tm = (tl + tr) / 2;

    return query(2*v, tl, tm, l, r) + query(2*v+1, tm, tr, l, r);
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

		if (id == 1 || id == 2) {
		    cin >> x;
			update(id, 1, 0, n, a - 1, b, x);
		}
		else {
            cout << query(1, 0, n, a - 1, b) << "\n";
		}
	}
}