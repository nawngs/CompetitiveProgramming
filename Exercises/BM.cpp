#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "BM";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fast_fre() {
	slow;
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

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

//############################################################

int n, m, q, scc = 0, cnt[200005], p[200005][21], h[200005], max_edge[200005][21], log2_n, x, y;

vector < pii > adj[200005];

//############################################################

void kruskal() {
	sort(edges.begin(), edges.end(), [](Edge &u, Edge &v) {
		return u.c < v.c;
	});
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
	}
}

//############################################################

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	cnt[u] = scc;
	for (auto v : adj[u]) {
		if (h[v.fi] != 0) continue;
		p[v.fi][0] = u;
		max_edge[v.fi][0] = v.se;
		dfs(v.fi);
	}
}

//################################################################

void init_LCA() {
	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			max_edge[i][j] = max(max_edge[i][j], max(max_edge[i][j - 1], max_edge[p[i][j - 1]][j - 1]));
		}
	}
}

int LCA(int u, int v) {
	int ans = -1;
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
	fast_fre();
	cin >> n >> m >> q;
	log2_n = log2(n) + 1;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v;
		c = i;
		edges.push_back({u, v, c});
	}
	kruskal();
	for (int i = 1; i <= n; i++) {
		if (!h[i]) {
			scc ++;
			dfs(i);
		}
	}
	init_LCA();
	while (q --) {
		cin >> x >> y;
		if (x == y) {
			cout << 0 << '\n';
			continue;
		}
		if (cnt[x] != cnt[y]) {
			cout << -1 << '\n';
			continue;
		}
		cout << LCA(x, y) << '\n';
	}
}
