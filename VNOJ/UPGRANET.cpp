#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c){};
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

int n, m, p[100005][18], val[100005][18], h[100005], log2_n;

vector < Edge > edges;

vector < pair < int, int > > adj[100005];

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == p[u][0]) continue;
		p[v.fi][0] = u;
		val[v.fi][0] = v.se;  
		dfs(v.fi);
	}
}

void init_LCA() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= log2_n; j++) {
			p[i][j] = -1;
			val[i][j] = 1e9;
		}
	}

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			if (p[i][j] != 0) val[i][j] = min(val[i][j], min(val[i][j - 1], val[p[i][j - 1]][j - 1]));
			//cout << i << " " << j << " " << p[i][j] << '\n';
		}

	}

}

int LCA(int u, int v) {
	int ans = 1e9;

	if (h[u] > h[v]) swap(u, v);

	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[p[v][j]] >= h[u]) {
			 	ans = min(ans, val[v][j]);
			 	v = p[v][j];
			 }
		} 
	}

	if (u == v) return ans;

	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0  && p[u][j] != p[v][j]) {
			ans = min(ans, min(val[u][j], val[v][j]));
			u = p[u][j];
			v = p[v][j];
		}
	}
	return min(ans, min(val[v][0], val[u][0]));
}

int main() {
	cin >> n >> m;
	dsu.init(n);
	log2_n = log2(n) + 1;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c});
	}
	sort(edges.begin(),edges.end(), [](Edge &x, Edge &y){
		return x.c > y.c;
	});
	//cout << 122 << '\n';
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		//cout << e.u << " " << e.v << " "<< e.c << '\n';
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
	}
	//cout << 122 << '\n';
	dfs(1);
	//cout << 122 << '\n';
	init_LCA();
	int ans = 0;
	for (auto e : edges) {
		ans += max(0, LCA(e.u, e.v) - e.c);
	}
	cout << ans;
}