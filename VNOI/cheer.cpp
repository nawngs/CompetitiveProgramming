#include <bits/stdc++.h>

using namespace std;

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

int n, p, a[10005];

vector < Edge > edges;

int main() {
	cin >> n >> p;
	dsu.init(n);
	int mina = 1e9;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	for (int i = 1; i <= p; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		c *= 2;
		c += a[u] + a[v];
		//cout << u << " " << v << " " << c << '\n';
		edges.push_back({u, v, c});
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	int ans = 0;
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		ans += e.c;
	}
	cout << ans + mina;
}