#include <bits/stdc++.h>
#define fi first
#define se second

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
	bool check(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		return true;
	}

	void join (int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return;
		par[root_v] = root_u;
		return ;
	}
} dsu1, dsu2;

int n, m1, m2;

int main() {
	cin >> n >> m1 >> m2;
	dsu1.init(n);
	dsu2.init(n);
	for (int i = 1; i <= m1; i++) {
		int u, v;
		cin >> u >> v;
		dsu1.join(u, v);
	}
	for (int i = 1; i <= m2; i++) {
		int u, v;
		cin >> u >> v;
		dsu2.join(u, v);
	}
	//cout << dsu1.par[3] << '\n'; 
	vector < pair < int, int > > res;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dsu1.check(i, j) && dsu2.check(i, j)) {
				dsu1.join(i, j);
				dsu2.join(i, j);
				res.push_back({i, j});
			}
		}
	}
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i].fi << " " << res[i].se << '\n';
}