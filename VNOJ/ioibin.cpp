//link:https://oj.vnoi.info/problem/ioibin
#include <bits/stdc++.h>

using namespace std;

const int nmax = 10000;

struct Dsu {
	vector < int > par;
	void init() {
		par.resize(nmax + 5, 0);
		for (int i = 1; i <= nmax; i++) par[i] = -1;
	}
	int find_root(int u) {
		return par[u] < 0 ? u : par[u] = find_root(par[u]);
	}
	void join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if(root_u == root_v) return ;
		if (par[root_u] < par[root_v]) swap(par[root_u], par[root_v]);
		par[root_v] += par[root_u];
		par[root_u] = root_v;
	}
} dsu;

int p;

int main() {
	cin >> p;
	dsu.init();
	while (p --) {
		int x, y, z;
		cin >> x >> y >> z;
		if(z == 1) dsu.join(x, y);
		else cout << (dsu.find_root(x) == dsu.find_root(y)) << '\n';
	}
}