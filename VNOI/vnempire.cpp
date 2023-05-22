//link: https://oj.vnoi.info/problem/vnempire

#include <bits/stdc++.h>
#define pii pair <int, int>
#define fi first
#define se second

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

int n;

pii a[100005], b[100005], c[100005];

vector < Edge > edges;

void create_edge(pii a[]) {
	sort (a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) 
		edges.push_back({a[i].se, a[i - 1].se, abs(a[i].fi - a[i - 1].fi)});
}

int main() {
	cin >> n;
	dsu.init(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> b[i].fi >> c[i].fi;
		a[i].se = b[i].se = c[i].se = i;
	}
	create_edge(a);
	create_edge(b);
	create_edge(c);
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	long long ans = 0;
	for (auto edge : edges) {
		if (!dsu.join(edge.u, edge.v)) continue;
		ans += edge.c;
	}
	cout << ans;
}
