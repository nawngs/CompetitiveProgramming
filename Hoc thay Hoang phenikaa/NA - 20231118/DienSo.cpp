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
const int N = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, a[N + 3], x[N + 3], dp[N + 3][2], sz[N + 3], h[N + 3];

vector < int > adj[N + 3];

int dfs(int u, int e) {
	sz[u] = 1;
	h[u] = h[e] + 1;
	for (auto v : adj[u]) if (v != e) sz[u] += dfs(v, u);
	if (h[u] > k) {
		dp[u][0] = 0;
		dp[u][1] = INF;
		return sz[u];
	}
	dp[u][0] = dp[u][1] = INF;
	if ((a[u] == -1 && x[h[u]] > 1) || (a[u] != -1 && a[u] < x[h[u]]))
		dp[u][0] = sz[u];
	if ((a[u] == -1 && x[h[u]] != m) || (a[u] != -1 && a[u] > x[h[u]])) 
		dp[u][0] = 0;
	if (a[u] == -1 || (a[u] == x[h[u]])) {
		int s = 1;
		for (auto v : adj[u]) if (v != e) s += dp[v][0];
		dp[u][0] = min(dp[u][0], s);
		for (auto v : adj[u]) if (v != e) dp[u][1] = min(dp[u][1], s - dp[v][0] + dp[v][1]);
		if (h[u] == k) dp[u][0] = dp[u][1] = 0;
	}
	//cout << u << " " << dp[u][0] << " " << dp[u][1] << '\n';
	return sz[u];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> x[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	cout << (dp[1][1] == INF ? -1 : dp[1][1] + 1);
}