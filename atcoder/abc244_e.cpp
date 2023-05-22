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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, s, t, x, dp[2003][2003][3];

vector < int > adj[2003];

void sol() {
	cin >> n >> m >> k >> s >> t >> x;
	k ++;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp, 255, sizeof(dp));
	dp[1][s][(s == x)] = 1;
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto pre : adj[j]) {
				if (dp[i - 1][pre][0] != -1) {
					if (dp[i][j][(j == x)] == -1) dp[i][j][(j == x)] = 0;
					dp[i][j][(j == x)] += dp[i - 1][pre][0];
					dp[i][j][(j == x)] %= MOD;
				}
				if (dp[i - 1][pre][1] != -1) {
					if (dp[i][j][(j != x)] == -1) dp[i][j][(j != x)] = 0;
					dp[i][j][(j != x)] += dp[i - 1][pre][1];
					dp[i][j][(j != x)] %= MOD;
				}
			}
			// cout << i << " " << j << " " << 0 << " " << dp[i][j][0] << '\n';
			// cout << i << " " << j << " " << 1 << " " << dp[i][j][1] << '\n';
		}
	}
	cout << (dp[k][t][0] == -1 ? 0 : dp[k][t][0]) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
