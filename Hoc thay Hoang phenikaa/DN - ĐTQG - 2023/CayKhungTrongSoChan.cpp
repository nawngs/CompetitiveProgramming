#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 18;

struct Edge {
	ll u, v, c;
	Edge() {
		u = v = c = 0;
	}
} edges[N + 3];

int n, m, dsu[N + 3];

bool choose[N + 3];

vector < int > adj[N + 3];

int find(int u) {
	return (u == dsu[u] ? u : dsu[u] = find(dsu[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	dsu[v] = u;
	return true;
}

int h[N + 3], par[N + 3][LG + 2], cnt[N + 3][LG + 2][2], pid[N + 3];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (int i = 1; i <= LG; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		for (int j = 0; j < 2; j++) cnt[u][i][j] = cnt[u][i - 1][j] + cnt[par[u][i - 1]][i - 1][j];
	}	
	for (auto id : adj[u]) {
		int v = edges[id].v ^ edges[id].u ^ u;
		if (v == e) continue;
		pid[v] = id;
		par[v][0] = u;
		cnt[v][0][edges[id].c & 1] = 1;
		dfs(v, u);
	}
}

int get(int u, int v, int md) {
	int dem = 0;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	dem += cnt[v][j][md];
			 	v = par[v][j];
			 }
		} 
	}
	if (u == v) return dem;
	for (int j = LG; j >= 0; j --) {
		if (par[u][j] != par[v][j]) {
			dem += cnt[u][j][md] + cnt[v][j][md];
			u = par[u][j]; v = par[v][j];
		}
	}
	dem += cnt[u][0][md] + cnt[v][0][md];
	return dem;
}

void upd(int u, int v, int md) {
	while (h[u] > h[v]) {
		if (cnt[u][0][md] == 1) {
			choose[pid[u]] = 0;
			return ;
		}
		u = par[u][0];
	}
	while (h[v] > h[u]) {
		if (cnt[v][0][md] == 1) {
			choose[pid[v]] = 0;
			return ; 
		}
		v = par[v][0];
	}
	while (1) {
		if (cnt[u][0][md] == 1) {
			choose[pid[u]] = 0;
			return ;
		}
		u = par[u][0];
		if (cnt[v][0][md] == 1) {
			choose[pid[v]] = 0;
			return ; 
		}
		v = par[v][0];
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
		cin >> edges[i].u >> edges[i].v >> edges[i].c;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	ll total = 0;
	for (int i = 1; i <= m; i++) if (join(edges[i].u, edges[i].v)) {
		total += edges[i].c;
		adj[edges[i].u].pb(i);
		adj[edges[i].v].pb(i);
		choose[i] = 1;
	}
	if (total % 2 == 0) {
		cout << "YES" << '\n';
		for (int i = 1; i <= m; i++) if (choose[i]) cout << i << " ";
		return 0;
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) if (!choose[i]) {
		if (get(edges[i].u, edges[i].v, (edges[i].c & 1) ^ 1)) {
			choose[i] = 1;
			upd(edges[i].u, edges[i].v, (edges[i].c & 1) ^ 1);
			cout << "YES" << '\n';
			for (int i = 1; i <= m; i++) if (choose[i]) cout << i << " ";
			return 0;
		}
	}
	cout << "NO" << '\n';
}