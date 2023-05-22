#include <bits/stdc++.h>
 
#define name "rally"
#define test "test"
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
 
int n, m, dp[500003], f2[500003];
 
pii f[500003], g[500003];
 
vector < int > adj[500003], adj_rev[500003];
 
int maxl = 0, cnt = 0, res, ans, pos;
 
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
 
bool vs[500003];
 
void dfs(int u) {
	vs[u] = 1; dp[u] = max(dp[u], f2[u] + g[u].fi - 1);
	//cout << u << " " << g[u].fi << " " << f2[u] << '\n';
	for (auto v : adj[u]) 
		if (!vs[v]) dfs(v);
}
 
void dfs1(int u) {
	f[u] = {1, 1}, f2[u] = 0;
	for (auto v : adj[u]) {
		if (f[v].fi == -INF) dfs1(v);
		if (f[u].fi < f[v].fi + 1) {
			f2[u] = f[u].fi;
			f[u] = f[v];
			f[u].fi += 1;
		}
		else if (f[u].fi == f[v].fi + 1) f[u].se += f[v].se;
		else f2[u] = max(f2[u], f[v].fi + 1);
	}
}
 
void dfs2(int u) {
	for (auto v : adj_rev[u]) {
		if (g[v].fi == -INF) dfs2(v);
		if (g[u].fi < g[v].fi + 1) {
			g[u] = g[v];
			g[u].fi += 1;
		}
		else if (g[u].fi == g[v].fi + 1) g[u].se += g[v].se;
	}
	if (g[u].fi == -INF) g[u] = {1, 1};
}
 
void dfs_find_res(int u, int e, int len) {
	ll val = max(dp[e], max(len - 1, maxl - len));
	if (f[u].se * g[u].se == cnt) {
		//if (u == 4) cout << e << " " << dp[e] << " " << len - 1 << " " << maxl - len << '\n';
		if (res > val) {
			res = val;
			ans = u;
		}
	}
	for (auto v : adj[u]) {
		if (len + f[v].fi == maxl) {
			dfs_find_res(v, u, len + 1);
			break;
		}
	}
}
 
int main() {
	fast;
	/*if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}*/
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		f[i].fi = g[i].fi = -INF;
	for (int i = 1; i <= n; i++) {
		if (f[i].fi == -INF) dfs1(i);
		if (g[i].fi == -INF) dfs2(i);
		if (maxl < f[i].fi) {
			maxl = f[i].fi, cnt = f[i].se;
			pos = i;
		}
		else if (maxl == f[i].fi) cnt += f[i].se;
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i);
	res = maxl, ans = 1;
	dfs_find_res(pos, 0, 1);
	cout << ans << " " << res - 1;
}