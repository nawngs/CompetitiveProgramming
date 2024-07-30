#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, par[NMAX + 3], in[NMAX + 3], out[NMAX + 3], timer = 0, it[6 * NMAX + 3], lazy[6 * NMAX + 3];

pii a[NMAX + 3];

vector < int > adj[NMAX + 3];

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node] * (r - l + 1);
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

void dfs(int u, int e) {
	in[u] = ++ timer;
	for (auto id : adj[u]) {
		int v = u ^ a[id].fi ^ a[id].se;
		if (v == e) continue;
		par[v] = u;
		dfs(v, u);
	}
	out[u] = timer;
}

void init(int u) {
	for (auto id : adj[u]) {
		int v = u ^ a[id].fi ^ a[id].se;
		if (v == par[u]) continue;
		if (u == a[id].fi) update(1, 1, n, in[v], out[v], 1);
		else {
			update(1, 1, n, 1, in[v] - 1, 1);
			update(1, 1, n, out[v] + 1, n, 1);
		}
		init(v);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> a[i].fi >> a[i].se;
		adj[a[i].fi].pb(i); adj[a[i].se].pb(i);
	}
	dfs(1, 0); init(1);
	while (q--) {
		int x, y; cin >> x >> y;
		if (x == 1) cout << query(1, 1, n, in[y], in[y]) << '\n';
		else {
			swap(a[y].fi, a[y].se);
			int val = 1;
			if (par[a[y].se] == a[y].fi) val = -1;
			int v = (par[a[y].se] == a[y].fi ? a[y].se : a[y].fi);
			update(1, 1, n, 1, in[v] - 1, val);
			update(1, 1, n, out[v] + 1, n, val);
			update(1, 1, n, in[v], out[v], 0 - val);
		}
	}
}