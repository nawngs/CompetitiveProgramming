#include <bits/stdc++.h>

#define int ll
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
const ll LINF = 1E12;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, c[2003], t[2003], f[2003][2003], g[2003][2003];

vector < int > adj[2003];

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
	if (sz(adj[u]) == 1 && u != 1) g[u][0] = 0;
	else {
		ll res = 0;
		for (auto v : adj[u]) {
			if (v == e) continue;
			res += f[v][0];
		}
		g[u][0] = min(g[u][0], res);
	}
	if (t[u] > 0) f[u][0] = min(f[u][0], g[u][0] + c[0]);
	if (sz(adj[u]) > 1 || u == 1) {
		for (auto v : adj[u]) {
			if (v == e) continue;
			f[u][0] = min(f[u][0], g[u][0] - f[v][0] + f[v][1]);
		}
	}
	for (int i = 1; i < n; i++) {
		g[u][i] = 0;
		for (auto v : adj[u]) {
			if (v == e) continue;
			g[u][i] += g[v][i - 1]; 
		}
		if (t[u] > i) f[u][i] = g[u][i] + c[i];
		for (auto v : adj[u]) {
			if (v == e) continue;
			f[u][i] = min(f[u][i], g[u][i] - g[v][i - 1] + f[v][i + 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) f[u][i] = min(f[u][i], f[u][i + 1]);
	g[u][0] = min(g[u][0], f[u][0]);
	for (int i = 1; i < n; i++) g[u][i] = min(g[u][i], g[u][i - 1]);

	// for (int i = 0; i < n; i++)
	// 	cout << u << " " << i << " " << f[u][i] << " " << g[u][i] << '\n';
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = g[i][j] = LINF;
	dfs(1, 0);
	cout << (f[1][0] == LINF ? -1 : f[1][0]);
}