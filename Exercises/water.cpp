#include <bits/stdc++.h>

#define name "water"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_u = find_root(par[u]);
		int root_v = find_root(par[v]);
		if (root_v == root_u) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges;

int n, m, maxe[4003][4003];

vector < pii > adj[4003];

void dfs(int u, int e, int Mx, int root) {
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		maxe[root][v.fi] = max(Mx, v.se);
		dfs(v.fi, u, max(Mx, v.se), root);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.push_back({u, v, c});
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	ll ans = 0;
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
		ans += 1ll * e.c;
	}
	for (int i = 1; i <= n; i++)
		dfs(i, 0, 0, i);
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		//cout << u << " " << v << '\n';
		cout << ans - 1ll * maxe[u][v] << '\n';
	}
}