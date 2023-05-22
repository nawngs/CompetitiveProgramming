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
const string dfn[] = {"none", "any", "at least one"};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v, c, id;
	Edge(int _u, int _v, int _c, int _id) : u(_u), v(_v), c(_c), id(_id) {};
};

int n, m, p[100003], res[100003], maxe[100003][18], h[100003], par[100003][18];

vector < Edge > edges, not_in_mst, adj[100003];

int find(int u) {
	return (u == p[u] ? u : p[u] = find(p[u]));
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	p[v] = u;
	return 1;
}

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (auto x : adj[u]) {
		int v = x.u + x.v - u, c = x.c;
		if (v == e) continue;
		maxe[v][0] = c;
		par[v][0] = u;
		p[v] = x.id;
		dfs(v, u);
	}
}

void dfs_update(int u, int e) {
	for (auto x : adj[u]) {
		int v = x.u + x.v - u, c = x.c;
		if (v == e) continue;
		if (maxe[v][0] == c) res[p[v]] = 2;
		else res[p[v]] = 1;
		dfs_update(v, u);
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	int res = -INF;
	if (h[u] != h[v]) {
		for (int j = 17; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	//cout << v << " " << j << " " << maxe[v][j] << '\n';
			 	res = max(res, maxe[v][j]);
			 	v = par[v][j];
			 }
		} 
	}
	if (u == v) return res;
	for (int j = 17; j >= 0; j--) {
		if (par[u][j] != 0 && par[u][j] != par[v][j]) {
			res = max(res, max(maxe[u][j], maxe[v][j]));
			u = par[u][j]; v = par[v][j];
		}
	}
	res = max(res, max(maxe[u][0], maxe[v][0]));
	return res;
}

void update(int u, int v, int val) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 17; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	maxe[v][j] = min(maxe[v][j], val);
			 	v = par[v][j];
			 }
		} 
	}
	if (u == v) return ;
	for (int j = 17; j >= 0; j--) {
		if (par[u][j] != 0 && par[u][j] != par[v][j]) {
			maxe[u][j] = min(maxe[u][j], val);
			maxe[v][j] = min(maxe[v][j], val);
			u = par[u][j]; v = par[v][j];
		}
	}
	maxe[u][0] = min(maxe[u][0], val);
	maxe[v][0] = min(maxe[v][0], val);
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.push_back({u, v, c, i});
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (auto e : edges) {
		int u = e.u, v = e.v, c = e.c;
		if (join(u, v)) {
			adj[u].push_back(e);
			adj[v].push_back(e);
		}
		else not_in_mst.push_back(e);
	}
	dfs(1, 0);
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] != 0)
				maxe[i][j] = max(maxe[i][j - 1], maxe[par[i][j - 1]][j - 1]);
		}
	//cout << LCA(2, 4) << '\n';
	for (auto e : not_in_mst) {
		int u = e.u, v = e.v, c = e.c;
		//cout << u << " " << v << " " << c << " " <<LCA(u, v) << '\n';
		int val = LCA(u, v);
		if (val == c) res[e.id] = 2;
		else res[e.id] = 0;
	}
	for (int j = 0; j <= 17; j++)
		for (int i = 1; i <= n; i++)
			maxe[i][j] = INF;
	for (auto e : not_in_mst) {
		int u = e.u, v = e.v, c = e.c;
		update(u, v, c);
	}
	for (int j = 17; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			maxe[i][j - 1] = min(maxe[i][j - 1], maxe[i][j]);
			maxe[par[i][j - 1]][j - 1] = min(maxe[par[i][j - 1]][j - 1], maxe[i][j]);
		}
	}
	dfs_update(1, 0);
	for (int i = 1; i <= m; i++) cout << dfn[res[i]] << '\n';
}
