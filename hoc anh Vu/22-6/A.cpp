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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v, c, index;
	Edge(int _u, int _v, int _c, int _index) : u(_u), v(_v), c(_c), index(_index){};
};

struct Data {
	int v, c, index;
	Data(int _v, int _c, int _index) : v(_v), c(_c), index(_index){};
};

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
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}

} dsu;

int n, m, p[200003][20], log2_n, h[200003], val[200003][20], up_id[200003], res[200003], par[200003];

vector < Edge > edges;

vector < Data > adj[200003];

bool check[200003];

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.v == p[u][0]) continue;
		up_id[v.v] = v.index;
		p[v.v][0] = u;
		val[v.v][0] = v.c;
		dfs(v.v);
	}
}

void init() {
	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			val[i][j] = max(val[i][j - 1], val[p[i][j - 1]][j - 1]);
		}
}

pii LCA(int u, int v) {
	int ans = 0;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[p[v][j]] >= h[u]) {
			 	ans = max(ans, val[v][j]);
			 	v = p[v][j];
			 }
		} 
	}
	if (u == v) return {u, ans};
	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0  && p[u][j] != p[v][j]) {
			ans = max(ans, max(val[u][j], val[v][j]));
			u = p[u][j];
			v = p[v][j];
		}
	}
	ans = max(ans, max(val[u][0], val[v][0]));
	return {p[u][0], ans};
}

int find_par(int x) {
	if (par[x] == x) return x;
	return par[x] = find_par(par[x]);
}

int main() {
	//fast;
	cin >> n >> m;
	log2_n = log2(n);
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c, i});
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	memset(check, false, sizeof(check));
	for (int i = 0; i < m; i++) {
		if (dsu.join(edges[i].u, edges[i].v)) {
			adj[edges[i].u].push_back({edges[i].v, edges[i].c, edges[i].index});
			adj[edges[i].v].push_back({edges[i].u, edges[i].c, edges[i].index});
			check[i] = 1;
		} 
	}
	dfs(1);
	init();
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		if (!check[i]) {
			pii tmp = LCA(edges[i].u, edges[i].v);
			res[edges[i].index] = tmp.se;
			int u = find_par(edges[i].u);
			int v = find_par(edges[i].v);
			while (h[u] > h[tmp.fi]) {
				//cout << u << " " << tmp.fi << '\n';
				par[u] = p[u][0];
				res[up_id[u]] = edges[i].c;
				u = find_par(u);
			}
			while (h[v] > h[tmp.fi]) {
				par[v] = p[v][0];
				res[up_id[v]] = edges[i].c;
				v = find_par(v);
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << res[i] - 1 << " ";
}
