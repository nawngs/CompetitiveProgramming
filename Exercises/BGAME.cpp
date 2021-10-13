#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges;

struct Dsu {
	vector < int > par;
	void init (int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = (find_root(par[u]));
	}
	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu; 

//###########################################################

int n, m, p[100005][18], h[100005], max_edge[100005][18], log2_n, vs[100005];

bool f[100005];

vector < pii > adj[100005];

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (vs[v.fi]) continue;
		p[v.fi][0] = u;
		max_edge[v.fi][0] = v.se;
		dfs(v.fi);
	}
}

void init_LCA() {
	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			max_edge[i][j] = max(max_edge[i][j], max(max_edge[i][j - 1], max_edge[p[i][j - 1]][j - 1]));
		}
	}
}

int LCA(int u, int v) {
	int ans = 0;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int i = log2_n; i >= 0; i --) {
			if (h[p[v][i]] >= h[u]) {
				ans = max(ans, max_edge[v][i]);
				v = p[v][i];
			}
		}
	}
	if (u == v) return ans;
	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0 && p[u][j] != p[v][j]) {
			ans = max(ans, max(max_edge[u][j], max_edge[v][j]));
			u = p[u][j];
			v = p[v][j];
		}
	}
	return max(ans, max(max_edge[u][0], max_edge[v][0]));
}

int main() {
	fastflow;
	//freopen("BGAME.INP", "r", stdin);
	cin >> n >> m;
	memset(vs, 0, sizeof(vs));
	log2_n = log2(n) + 1;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c});
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
		return x.c > y.c;
	});
	for (int i = 0; i < edges.size(); i++) {
		auto e = edges[i];
		if (!dsu.join(e.u, e.v)) continue;
		//cout << e.u << " " << e.v << " " << e.c << '\n';
		f[i] = true;
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
	}
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) dfs(i);
	}
	init_LCA();
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		auto e = edges[i];
		if (f[i] == false) {
			//cout << e.u << " " << e.v << " " << e.c << " " << LCA(e.u, e.v) << '\n';
			res = max(res, e.c + LCA(e.u, e.v));
		}
	}
	cout << res;
}