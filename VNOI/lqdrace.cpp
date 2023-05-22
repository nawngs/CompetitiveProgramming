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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct CentroidDecomposition {
	set < pii > adj[nmax + 3];
	map < int, pii > d[nmax + 3];
	int sze[nmax + 3], par[nmax + 3];
		void init(int n) {
		for (int i = 1; i <= n; i++) adj[i].clear();
	}
	void add_edge(int u, int v, int c) {
		adj[u].insert({v, c});
		adj[v].insert({u, c});
	}
	int dfs(int u, int e) {
		sze[u] = 1;
		for (auto v : adj[u]) {
			if (v.fi == e) continue;
			sze[u] += dfs(v.fi, u);
		}
		return sze[u];
	}
	int centroid(int u, int e, int total) {
		for (auto v : adj[u]) {
			if (v.fi == e) continue;
			if (sze[v.fi] > total / 2) return centroid(v.fi, u, total);
		}
		return u;
	}
	void dfs2(int u, int e, int pos, int len, int cnt) {
		d[pos][u] = {len, cnt};
		for (auto v : adj[u]) {
			if (v.fi == e) continue;
			dfs2(v.fi, u, pos, len + v.se, cnt + 1);
		}
	}
	void build(int u, int e) {
		int total = dfs(u, e);
		int c = centroid(u, e, total);
		if (e == -1) e = c;
		par[c] = e;
		dfs2(c, e, c, 0, 0);
		vector < pii > tmp(adj[c].begin(), adj[c].end());
		for (auto v : tmp) {
			adj[c].erase(v);
			adj[v.fi].erase({c, v.se});
			build(v.fi, c);
		}
	}

}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
