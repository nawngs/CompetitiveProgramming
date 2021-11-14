#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

//#######################################################################
//freopen

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

//#######################################################################
// kieu du lieu canh

struct Edge {
	int u, v, c, stt;
	Edge(int _u, int _v, int _c, int _stt) : u(_u), v(_v), c(_c), stt(_stt) {};
};

//#######################################################################
// dsu(cay khung) 

struct DSU {
	vector < int > par;

	void init (int n) {
		par.resize(n + 5);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}

	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu;

//#######################################################################
//du lieu can thiet

int n, m, h[200005], p[200005][21], val[200005][21], log2_n;

ll res[200005];

vector < pii > adj[200005];

vector < Edge > edges;

//#######################################################################
// dfs
void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == p[u][0]) continue;
		p[v.fi][0] = u;
		val[v.fi][0] = v.se;
		dfs(v.fi);
	}
}

//#######################################################################
// LCA

void init_LCA() {
	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) val[i][j] = -INF;

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			if (p[i][j] != 0) val[i][j] = max(val[i][j], max(val[i][j - 1], val[p[i][j - 1]][j - 1]));
		}
	}
}

int LCA(int u, int v) {
	int ans = -INF;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[p[v][j]] >= h[u]) {
				ans = max(ans, val[v][j]);
				v = p[v][j];
			}
		}
	}
	if (u == v) return ans;
	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0 && p[u][j] != p[v][j]) {
			ans = max(ans, max(val[u][j], val[v][j]));
			u = p[u][j];
			v = p[v][j];
		}
	}
	return max(ans, max(val[u][0], val[v][0]));
}

//#######################################################################
// solution

void sol() {
	cin >> n >> m;
	log2_n = log2(n) + 1;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c, i});
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	ll sum = 0;
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
		sum = sum + 1ll * e.c;
	}
	dfs(1);
	init_LCA();
	for (auto e : edges) res[e.stt] = sum - 1ll * LCA(e.u, e.v) + 1ll * e.c;
	for (int i = 1; i <= m; i++) cout << res[i] << "\n";
}

//#######################################################################
//main
int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
