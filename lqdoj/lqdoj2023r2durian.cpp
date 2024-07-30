#include <bits/stdc++.h>

#define name "durian"
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

int n, k;

vector < int > adj[NMAX + 3];

namespace sub12 {
	const int N = 5E3;
	int dp[N + 3][N + 3], from[N + 3], to[N + 3], h[N + 3], res = 0, total[N + 3];
	void dfs(int u, int e) {
		h[u] = h[e] + 1; from[u] = h[u]; to[u] = from[u];
		dp[u][h[u]] = 1;
		for (auto v : adj[u]) if (v != e) {
			dfs(v, u);
			for (int i = to[v]; i >= from[v]; i--) dp[u][i] = max(dp[u][i], dp[v][i]);
			to[u] = max(to[u], to[v]);
		}
		for (auto v : adj[u]) if (v != e) 
			for (int i = from[v]; i <= to[v]; i++) total[i] += dp[v][i];
		for (int i = from[u]; i <= to[u]; i++) {
			int j = k + 2 * h[u] - i;
			if (j < i) continue;
			if (i == from[u]) dp[u][i] = max(dp[u][i], total[j] + 1);
			for (auto v : adj[u]) if (v != e) {
				dp[u][i] = max(dp[u][i], dp[v][i] + total[j] - dp[v][j]);
			}
		}
		for (int i = from[u]; i <= to[u]; i++) total[i] = 0, res = max(res, dp[u][i]);
		for (int i = to[u] - 1; i >= from[u]; i--) dp[u][i] = max(dp[u][i], dp[u][i + 1]);
		// for (int i = 0; i < k; i++) cout << u << " " << i << " " << dp[u][i + from[u]] << '\n';
	}
	void solve() {
		dfs(1, 0);
		cout << res << '\n';
	}
}

namespace sub3 {
	int dp[NMAX + 3][23], total[23], res = 0;
	void dfs(int u, int e) {
		dp[u][0] = 1;
		for (auto v : adj[u]) if (v != e) {
			dfs(v, u);
			//if (u == 2) for (int i = 0; i < k; i++) cout << 123 << " " << v << " " << i << " " << dp[v][i] << '\n';
		}
		for (int i = 0; i <= k; i++) total[i] = 0;
		for (auto v : adj[u]) if (v != e) {
			for (int i = 0; i < k; i++) {
				total[i + 1] += dp[v][i];
				dp[u][i + 1] = max(dp[u][i + 1], dp[v][i]);
			}
		}
		dp[u][0] += total[k];
		res = max(res, dp[u][0]);
		for (int i = 1; i < k; i++) {
			if (i > k - i) break;
			for (auto v : adj[u]) if (v != e) {
				dp[u][i] = max(dp[u][i], dp[v][i - 1] + total[k - i] - dp[v][k - i - 1]);
				//if (u == 4 && i == 1) cout << dp[u][i] << " " << dp[v][i - 1] << " " << total[k - i] << " " << dp[v][k - i - 1] << '\n';
			}
			res = max(res, dp[u][i]);
		}
		for (int i = k - 2; i >= 0; i--) dp[u][i] = max(dp[u][i], dp[u][i + 1]);
		// for (int i = 0; i < k; i++) cout << u << " " << i << " " << dp[u][i] << '\n';
	}
	void solve() {
		dfs(1, 0);
		cout << res;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	//  if (n <= 5000) sub12::solve();
	// else 
	if (k <= 20) sub3::solve();
} 