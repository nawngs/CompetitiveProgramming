#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "balls";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, q, u, v, l, r;

pll it_n[400003], it_m[400003];

ll lazy_n[400003], lazy_m[400003];

ll calc(ll l, ll r) {
	return (r + l) * (r - l + 1) / 2;
}

pll merge(pll x, pll y) {
	return make_pair(x.fi + y.fi, x.se + y.se);
}

//##############################################################################

void update_node_n(int node, int l, int r) {
	if (lazy_n[node] != 0) {
		it_n[node].fi += calc(l, r) * lazy_n[node];
		it_n[node].se += (r - l + 1) * lazy_n[node];
		if (l != r) {
			lazy_n[node * 2] += lazy_n[node];
			lazy_n[node * 2 + 1] += lazy_n[node];
 		}
 		lazy_n[node] = 0;
	}
}

void update_n(int node, int l, int r, int val, int u, int v) {
	update_node_n(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy_n[node] = val;
		update_node_n(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update_n(node * 2, l, mid, val, u, v);
	update_n(node * 2 + 1, mid + 1, r, val, u, v);
	it_n[node] = merge(it_n[node * 2], it_n[node * 2 + 1]);
}

pll query_n(int node, int l, int r, int u, int v) {
	update_node_n(node, l, r);
	if (v < l || r < u) return make_pair(0, 0);
	if (u <= l && r <= v) return it_n[node];
	int mid = (l + r) / 2;
	return merge(query_n(node * 2, l, mid, u, v), query_n(node * 2 + 1, mid + 1, r, u, v));
}

ll calc_n(ll x) {
	pll lnode = query_n(1, 0, n, 1, x);
	pll rnode = query_n(1, 0, n, x + 1, n);
	return x * lnode.se - lnode.fi + rnode.fi - rnode.se * x;
}

//##############################################################################

void update_node_m(int node, int l, int r) {
	if (lazy_m[node] != 0) {
		it_m[node].fi += calc(l, r) * lazy_m[node];
		it_m[node].se += lazy_m[node];
		if (l != r) {
			lazy_m[node * 2] += lazy_m[node];
			lazy_m[node * 2 + 1] += lazy_m[node];
		}
		lazy_m[node] = 0;
	}
}

void update_m(int node, int l, int r, int val, int u, int v) {
	update_node_m(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy_m[node] += val;
		update_node_m(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update_m(node * 2, l, mid, val, u, v);
	update_m(node * 2 + 1, mid + 1, r, val, u, v);
	it_m[node] = merge(it_m[node * 2], it_m[node * 2 + 1]);
}

pll query_m(int node, int l, int r, int u, int v) {
	update_node_m(node, l, r);
	if (v < l || r < u) return make_pair(0, 0);
	if (u <= l && r <= v) return it_m[node];
	int mid = (l + r) / 2;
	return merge(query_m(node * 2, l, mid, u, v), query_m(node * 2 + 1, mid + 1, r, u, v));
}

ll calc_m(ll x) {
	pll lnode = query_m(1, 0, m, 1, x);
	pll rnode = query_m(1, 0, m, x + 1, m);
	return x * lnode.se - lnode.fi + rnode.fi - rnode.se * x;
}

//##############################################################################

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n >> m >> q;
	while (q--) {
		cin >> u >> v >> l >> r;
		update_n(1, 0, n, (r - l) + 1, u, v);
		update_m(1, 0, m, (u - v) + 1, l, r);
		ll total = it_n[1].se;
		int l = 0, r = n, mid, ans = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query_n(1, 0, n, 1, mid).se <= total / 2) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		//cout << ans << '\n';
		ll res = min(calc_n(ans), calc_n(ans + 1));
		l = 0, r = m, ans = m;
		total = it_m[1].se;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query_m(1, 0, m, 1, mid).se <= total / 2) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		//cout << ans << '\n';
		res = res + min(calc_m(ans), calc_m(ans + 1));
		cout << res % MOD << ' ';
	}
}
