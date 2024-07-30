#include <bits/stdc++.h>

#define name "shopping"
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
const int NMAX = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, b, d[NMAX + 3], c[NMAX + 3], dp[NMAX + 3][NMAX + 3][2], sze[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	for (int j = 0; j <= n; j++) dp[u][j][0] = dp[u][j][1] = LINF;
	dp[u][0][0] = 0;
	dp[u][1][0] = c[u]; dp[u][1][1] = d[u];
	sze[u] = 1;
	for (auto v : adj[u]) {
		dfs(v);
		for (int i = sze[u]; i >= 0; i--) {
			for (int j = 0; j <= sze[v]; j++) {
				dp[u][i + j][0] = min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
				dp[u][i + j][1] = min(dp[u][i + j][1], dp[u][i][1] + min(dp[v][j][1], dp[v][j][0]));
			}
		}
		sze[u] += sze[v];
	}
	// for (int i = 0; i <= sze[u]; i++) cout << u << " " << i << " " << dp[u][i][0] << " " << dp[u][i][1] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> b >> c[1] >> d[1];
	d[1] = c[1] - d[1];
	for (int i = 2; i <= n; i++) {
		int u; cin >> c[i] >> d[i] >> u;
		d[i] = c[i] - d[i];
		adj[u].pb(i);
	}
	dfs(1);
	for (int j = n; j >= 0; j--) {
		if (dp[1][j][0] <= b || dp[1][j][1] <= b) {
			cout << j << '\n';
			return 0;
		}
	}
}