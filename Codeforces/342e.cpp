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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct CentroidDecomposition {
	set < int > adj[nmax + 3];
	map < int, int > d[nmax + 3];
	int sze[nmax + 3], par[nmax + 3], ans[nmax + 3];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			ans[i] = INF;
		}
	}
	void add_edge(int u, int v) {
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int dfs(int u, int e) {
		sze[u] = 1;
		for (auto v : adj[u]) {
			if (v == e) continue;
			sze[u] += dfs(v, u);
		}
		return sze[u];
	}
	int centroid(int u, int e, int total) {
		for (auto v : adj[u]) {
			if (v == e) continue;
			if (sze[v] > total / 2) return centroid(v, u, total);
		}
		return u;
	}
	void dfs2(int u, int e, int pos, int len) {
		d[pos][u] = len;
		for (auto v : adj[u]) {
			if (v == e) continue;
			dfs2(v, u, pos, len + 1);
		}
	}
	void build(int u, int e) {
		int total = dfs(u, e);
		int c = centroid(u, e, total);
		if (e == -1) e = c;
		par[c] = e;
		dfs2(c, e, c, 0);
		vector<int> tmp(adj[c].begin(), adj[c].end());
		for (auto v : tmp) {
			adj[c].erase(v);
			adj[v].erase(c);
			build(v, c);
		}
	}
	void add(int u) {
		for (int v = u; v != 0; v = par[v]) ans[v] = min(ans[v], d[v][u]);
	}
	int query(int u) {
		int res = INF;
		for (int v = u; v != 0; v = par[v]) res = min(res, ans[v] + d[v][u]);
		return res;
	}
} cd;

int n, m;

int main() {
	fast;
	cin >> n >> m;
	cd.init(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		cd.add_edge(u, v);
	}
	cd.build(1, 0);
	cd.add(1);
	while (m--) {
		int t, u;
		cin >> t >> u;
		if (t == 1) cd.add(u);
		else cout << cd.query(u) << '\n';
	}
}
