#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
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
	bool join (int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu;

int n, m;

vector < Edge > edges;

int main() {
	cin >> n >> m;
	dsu.init(n);
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		sum += c;
		edges.push_back({u, v, c});
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c > y.c;
	});
	int ans = 0;
	for (auto edge : edges) {
		if(!dsu.join(edge.u, edge.v)) continue;
		ans += edge.c;
	}
	cout << sum - ans;
}