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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, vs[NMAX + 3], ID[NMAX + 3], f[NMAX + 3], g[NMAX + 3], it[6 * NMAX + 3], lazy[6 * NMAX + 3];

vector < int > G[NMAX + 3], Grev[NMAX + 3], topo;

vector < pii > edges;

void dfs(int u) {
	vs[u] = 1;
	for (auto v : G[u]) {
		assert(vs[v] != 1);
		if (vs[v]) continue;
		dfs(v);
	}
	topo.pb(u);
	vs[u] = 2;
}


void update(int node, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = max(lazy[node], val);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
}

int query(int node, int l, int r, int u) {
	if (l == r) return lazy[node];
	int mid = (l + r) / 2;
	if (u <= mid) return max(lazy[node], query(lnode, u));
	else return max(lazy[node], query(rnode, u));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
		G[u].pb(v); Grev[v].pb(u);
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i);
	reverse(topo.begin(), topo.end());
	for (int i = 0; i < n; i++) ID[topo[i]] = i;
	for (int i = 0; i < n; i++) {
		int u = topo[i];
		for (auto v : G[u]) f[ID[v]] = max(f[ID[v]], f[i] + 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		int u = topo[i];
		for (auto v : Grev[u]) g[ID[v]] = max(g[ID[v]], g[i] + 1);
	}
	// for (int i = 0; i < n; i++) cout << topo[i] << " " << f[i] << " " << g[i] << '\n';
	for (auto u : edges) {
		// cout << u.fi << " " << u.se << " " << ID[u.fi] + 1 << " " << ID[u.se] - 1 << " " << f[ID[u.fi]] + g[ID[u.se]] + 1 << '\n';
		update(1, 0, n - 1, ID[u.fi] + 1, ID[u.se] - 1, f[ID[u.fi]] + g[ID[u.se]] + 1);
	}
	for (int i = n - 2; i >= 0; i--) g[i] = max(g[i], g[i + 1]);
	pii res = {INF, INF};
	for (int i = 0; i < n; i++) {
		if (i) f[i] = max(f[i], f[i - 1]);
		pii val = {max({query(1, 0, n - 1, i), (i ? f[i - 1] : 0), g[i + 1]}), topo[i]};
		// cout << topo[i] << " " << query(1, 0, n - 1, i, i) << " " << (i ? f[i - 1] : 0) << " " << g[i + 1] << '\n';
		res = min(res, val);
	}
	cout << res.se << " " << res.fi << '\n';
}