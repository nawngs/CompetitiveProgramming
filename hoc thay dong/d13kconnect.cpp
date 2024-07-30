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

int par[N + 3], sze[N + 3], cnt[N + 3], res[N + 3], dp[N + 3], a[N + 3], n, m, k;

pii edges[N + 3];

vector < int > adj[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}
bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	if (sze[u] < sze[v]) swap(u, v);
	par[v] = u; sze[u] += sze[v]; cnt[u] += cnt[v];
	return true;
}

void dfs(int u, int e) {
	for (auto id : adj[u]) {
		int v = edges[id].fi ^ edges[id].se ^ u;
		if (v == e) continue;
		dfs(v, u);
		dp[u] += dp[v];
		if (dp[v] == 0) res[id] = 0;
	}
	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		cin >> edges[i].fi >> edges[i].se;
	for (int i = 1; i <= n; i++) par[i] = i, sze[i] = 1;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
		dp[a[i]] ++;
	}
	for (int i = 1; i <= m; i++) if (join(edges[i].fi, edges[i].se)) {
		res[i] = 1;
		adj[edges[i].fi].pb(i);
		adj[edges[i].se].pb(i);
	}
	dfs(a[1], 0);
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
	
}