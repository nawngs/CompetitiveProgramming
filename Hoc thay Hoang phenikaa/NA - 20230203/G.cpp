#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Edge {
	int u, v, l, r;
} edges[500003];

int n, m, maxe[500003][20], par[500003][20], lazy[500003][20], h[500003], res[500003];

vector < int > adj[500003], pos[500003];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (int j = 1; j <= 19; j++) {
		par[u][j] = par[par[u][j - 1]][j - 1];
		maxe[u][j] = max(maxe[u][j - 1], maxe[par[u][j - 1]][j - 1]);
		lazy[u][j] = INF;
	}
	for (auto i : adj[u]) {
		int v = edges[i].u + edges[i].v - u;
		if (v == e) continue;
		par[v][0] = u; maxe[v][0] = edges[i].l; lazy[v][0] = INF;
		dfs(v, u);
	}
}

int query(int u, int v) {
	int res = -INF;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 19; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				res = max(res, maxe[v][j]);
				v = par[v][j]; 
			}
		}
	}
	if (u == v) return res;
	for (int j = 19; j >= 0; j--) 
		if (par[u][j] != par[v][j]) {
			res = max(res, maxe[u][j]); res = max(res, maxe[v][j]);
			u = par[u][j]; v = par[v][j];
		}
	res = max(res, maxe[u][0]); res = max(res, maxe[v][0]);
	return res;
}

void update(int u, int v, int x) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 19; j >= 0; j--)
			if (h[par[v][j]] >= h[u]) {
				lazy[v][j] = min(lazy[v][j], x);
				v = par[v][j];
			}
	}
	if (u == v) return ;
	for (int j = 19; j >= 0; j--) 
		if (par[u][j] != par[v][j]) {
			lazy[u][j] = min(lazy[u][j], x); lazy[v][j] = min(lazy[v][j], x);
			u = par[u][j]; v = par[v][j];
		}
	lazy[u][0] = min(lazy[u][0], x); lazy[v][0] = min(lazy[v][0], x);
}

void dfs(int u) {
	for (auto i : adj[u]) {
		int v = edges[i].u + edges[i].v - u;
		if (v == par[u][0]) continue;
		edges[i].r = min(edges[i].r, lazy[v][0] - 1);
		dfs(v);
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].l >> edges[i].r;
		if (i < n) adj[edges[i].u].pb(i), adj[edges[i].v].pb(i);
		pos[i].clear();
	}
	dfs(1, 0);
	for (int i = n; i <= m; i++) {
		edges[i].l = max(edges[i].l, query(edges[i].u, edges[i].v) + 1);
		update(edges[i].u, edges[i].v, edges[i].r);
	}
	for (int j = 19; j >= 1; j--) 
		for (int i = 1; i <= n; i++) {
			lazy[i][j - 1] = min(lazy[i][j - 1], lazy[i][j]);
			lazy[par[i][j - 1]][j - 1] = min(lazy[par[i][j - 1]][j - 1], lazy[i][j]);
		}
	dfs(1);
	for (int i = 1; i <= m; i++) {
		if (edges[i].l > edges[i].r) {
			cout << "NO" << '\n';
			return ;
		}
		pos[edges[i].l].pb(i);
	}
	set < pii > ms;
	for (int w = 1; w <= m; w++) {
		for (auto x : pos[w]) 
			ms.insert({edges[x].r, x});
		if (ms.empty()) {
			cout << "NO" << '\n';
			return ;
		}
		pii temp = *ms.begin(); ms.erase(ms.begin());
		if (temp.fi < w) {
			cout << "NO" << '\n';
			return ;
		}
		res[temp.se] = w;
 	}
 	cout << "YES" << '\n';
 	for (int i = 1; i <= m; i++) cout << res[i] << " ";
 	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}