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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 20;

int n, m, dsu[N + 3], par[N + 3][LG + 3], dp[N + 3][LG + 3], res[2 * N + 3], h[N + 3];

pii e[2 * N + 3];

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

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	par[u][0] = e; dp[u][0] = INF;
	for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1], dp[u][i] = INF;
	for (auto v : adj[u]) if (v != e) dfs(v, u);
}

void solve(int u, int v, int x) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				dp[v][j] = min(dp[v][j], x);
				v = par[v][j];
			} 
		}
	}
	if (u == v) return ;
	for (int j = LG; j >= 0; j--) {
		if (par[u][j] != par[v][j]) {
			dp[u][j] = min(dp[u][j], x); dp[v][j] = min(dp[v][j], x);
			u = par[u][j]; v = par[v][j];
		}
	}
	dp[u][0] = min(dp[u][0], x); dp[v][0] = min(dp[v][0], x);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].fi >> e[i].se;
		if (join(e[i].fi, e[i].se)) adj[e[i].fi].pb(e[i].se), adj[e[i].se].pb(e[i].fi);
		else res[i] = 1;
	}
	for (int i = 1; i <= n; i++) if (h[i] == 0) dfs(i, 0);
	for (int i = 1; i <= m; i++) if (res[i] == 1) 
		solve(e[i].fi, e[i].se, i);
	for (int j = LG; j > 0; j--) 
	for (int i = 1; i <= n; i++) {
		dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
		dp[par[i][j - 1]][j - 1] = min(dp[par[i][j - 1]][j - 1], dp[i][j]);
	}
	for (int i = 2; i <= n; i++) if (dp[i][0] != INF) res[dp[i][0]] ++;
	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}