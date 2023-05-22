#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, s, dp[10003][10003][2];

vector < pii > adj[10003];

void dfs(int u, int e = 0) {
	dp[u][1][0] = dp[u][1][1] = 0;
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);	
		for (int i = 1; i <= k; i++) {
			if (dp[u][i][1] == INF) break;
			for (int j = 1; j < k; j++) {
				if (dp[v.fi][j][1] == INF) break;
				dp[u][i + j][1] = min(dp[u][i + j][1], dp[u][i][1] + dp[v.fi][j][1] + 2 * v.se);
				dp[u][i + j][0] = min(dp[u][i + j][0], min(dp[u][i][0] + dp[v.fi][j][1] + 2 * v.se, dp[u][i][1] + dp[v.fi][j][0] + v.se));
			}
		}
	}
}

int main() {
	fast;
	cin >> n >> k >> s;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= k; j++) dp[i][j][0] = dp[i][j][1] = INF;
	dfs(s);
	cout << dp[s][k][0];
}
