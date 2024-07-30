#include <bits/stdc++.h>

#define pb push_back
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int N = 1e5;
const int MOD = 1E9 + 7;

int n, m, a[N + 3], dp[N + 3], sze[N + 3];

bool vs[N + 3];

vector < pii > adj[N + 3];

void add(int &x, int y) {
	if ((x += y) >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int mul(int x, int y) {
	return 1ll * x * y % MOD;
}

int dfs(int u, int e) {
	vs[u] = 1;
	sze[u] = 1;
	for (auto v : adj[u]) if (v.fi != e) {
		sze[u] += dfs(v.fi, u);
		add(dp[u], dp[v.fi]);
		add(dp[u], mul(v.se, mul(sze[v.fi], n - sze[v.fi])));
	
	}
	return sze[u];
}

int reroot(int u, int e) {
	int res = dp[u];
	for (auto it : adj[u]) if (it.fi != e) {
		int v, w; tie(v, w) = it;
		add(sze[u], -sze[v]);
		add(dp[u], -dp[v]); add(dp[u], -mul(w, mul(sze[v], n - sze[v])));
		add(sze[v], sze[u]);
		add(dp[v], dp[u]); add(dp[v], mul(w, mul(sze[u], n - sze[u])));
		res = min(res, reroot(v, u));
		add(sze[v], -sze[u]);
		add(dp[v], -dp[u]); add(dp[v], mul(w, -mul(sze[u], n - sze[u])));
		add(sze[u], sze[v]);
		add(dp[u], dp[v]); add(dp[u], mul(w, mul(sze[v], n - sze[v])));
		
		
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("BUILDTREE.inp", "r", stdin);
   	// freopen("BUILDTREE.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i < n - m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); adj[v].pb({u, c});
	}
	int res = 0;
	vector < int > scc;
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		dfs(i, 0);
		scc.pb(sze[i]);
		add(res, reroot(i, 0));
	}
	sort(scc.begin(), scc.end());
	sort(a + 1, a + m + 1, greater < int >());
	for (int i = 1; i <= m; i++) 
		add(res, mul(a[i], mul(scc[i - 1], n - scc[i - 1])));
	cout << res;
}