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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, D;

vector < int > adj[NMAX + 3];

pii h[NMAX + 3];

void dfs(int u, int e) {
	h[u] = {h[e].fi + 1, u};
	for (auto v : adj[u]) if (v != e) dfs(v, u);
}

int sze[NMAX + 3], par[NMAX + 3], f[NMAX + 3];

bool used[NMAX + 3];

unordered_map < int, int > d[NMAX + 3];

int dfs1(int u, int e) {
	sze[u] = 1;
	for (auto v : adj[u]) if (v != e && !used[v]) sze[u] += dfs1(v, u);
	return sze[u];
}

int find(int u, int e, int total) {
	for (auto v : adj[u]) if (v != e && !used[v]) 
		if (sze[v] * 2 >= total) return find(v, u, total);
	return u;
}

void dfs2(int u, int e, int C, int len) {
	d[C][u] = len;
	for (auto v : adj[u]) if (v != e && !used[v]) dfs2(v, u, C, len + 1);
}

void centroid(int u, int e) {
	int C = find(u, e, dfs1(u, e));
	used[C] = 1; par[C] = e; f[C] = INF;
	dfs2(C, e, C, 0);
	for (auto v : adj[C]) if (!used[v]) centroid(v, C);
}

int query(int u) {
	int res = INF;
	for (int v = u; v != 0; v = par[v]) res = min(res, f[v] + d[v][u]);
	return res;
}

void add(int u) {
	for (int v = u; v > 0; v = par[v]) f[v] = min(f[v], d[v][u]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> D;
	for (int x, i = 2; i <= n; i++) {
		cin >> x; x ++;
		adj[x].pb(i); adj[i].pb(x);
	}
	dfs(1, 0);
	sort(h + 1, h + n + 1, greater < pii >());
	centroid(1, 0);
	int res = 0;
	for (int i = 1; i <= n; i++) 
		if (query(h[i].se) >= D) res ++, add(h[i].se);
	cout << res;
}