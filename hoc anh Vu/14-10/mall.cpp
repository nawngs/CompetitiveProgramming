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

int n, d;

pii h[200003];

vector < int > adj[200003];

void dfs(int u) {
	for (auto v : adj[u]) {
		h[v] = {h[u].fi + 1, v};
		dfs(v);
	}
}

struct CentroidDecomposition {
	vector < int > adj[nmax + 3];
	map < int, int > d[nmax + 3];
	int sze[nmax + 3], par[nmax + 3], ans[nmax + 3];
	int used[nmax + 3];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			ans[i] = INF;
			used[i] = false;
		}
	}
	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int dfs(int u, int e) {
		sze[u] = 1;
		for (auto v : adj[u]) {
			if (v == e || used[v]) continue;
			sze[u] += dfs(v, u);
		}
		return sze[u];
	}
	int centroid(int u, int e, int total) {
		for (auto v : adj[u]) {
			if (v == e || used[v]) continue;
			if (sze[v] > total / 2) return centroid(v, u, total);
		}
		return u;
	}
	void dfs2(int u, int e, int pos, int len) {
		d[pos][u] = len;
		for (auto v : adj[u]) {
			if (v == e || used[v]) continue;
			dfs2(v, u, pos, len + 1);
		}
	}
	void build(int u, int e) {
		int c = centroid(u, e, dfs(u, e));
		if (e == -1) e = c;
		par[c] = e;
		used[c] = 1;
		dfs2(c, e, c, 0);
		for (auto v : adj[c]) {
			if (v == e || used[v]) continue;
			build(v, c);
		}
	}
	void add(int u) {
		for (int v = u; v != 0; v = par[v]) 
			ans[v] = min(ans[v], d[v][u]);
	}
	int query(int u) {
		int res = INF;
		for (int v = u; v != 0; v = par[v]) 
			res = min(res, ans[v] + d[v][u]);
		return res;
	}
} cd;

int main() {
	fast;
	cin >> n >> d;
	cd.init(n);
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		x ++;
		adj[x].push_back(i);
		cd.add_edge(x, i);
	}
	dfs(1);
	sort(h + 1, h + n + 1);
	h[1] = {0, 1};
	cd.build(1, 0);
	int res = 0;
	for (int i = n; i >= 1; i--) {
		if (cd.query(h[i].se) < d) continue;
		res ++;
		cd.add(h[i].se);
	}
	cout << res << '\n';
}
