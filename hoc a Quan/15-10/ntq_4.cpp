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

int n, s, a[5003], total[5003], dp[5003][10003];

vector < pii > adj[5003];

void dfs(int u, int e) {
	dp[u][0] = a[u];
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);
		for (int i = min(s, total[u]); i >= 0; i--) {
			for (int j = 0; j <= total[v.fi]; j++) {
				if (i + v.se + j > s) break;
				dp[u][i + v.se + j] = max(dp[u][i + v.se + j], dp[u][i] + dp[v.fi][j]);
			}
		}
		total[u] += total[v.fi] + v.se;
	} 	
}

int main() {
	fast;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(1, 0);
	int res = 0;
	for (int i = 1; i <= s; i++) res = max(res, dp[1][i]);
	cout << res;
}
