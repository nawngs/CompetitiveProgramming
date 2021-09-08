#include <bits/stdc++.h>

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
		if (root_v == root_u) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu;

int n;

vector < Edge > edges;

int main() {
	cin >> n;
	dsu.init(n);
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		edges.push_back({i, n + 1, c});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c;
			cin >> c;
			if(j > i) edges.push_back({i, j, c});
		}
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	int ans = 0;
	for (auto edge : edges) {
		if (!dsu.join(edge.u, edge.v)) continue;
		ans += edge.c;
	}
	cout << ans;
}