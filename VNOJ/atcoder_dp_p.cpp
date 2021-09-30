#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, dp[100005][3];

vector < int > adj[100005];

void dfs(int u, int e) {
	ll sum0 = 1, sum1 = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		sum1 *= dp[v][0];
		sum1 %= MOD;
		sum0 *= (dp[v][0] + dp[v][1]);
		sum0 %= MOD;
	}
	dp[u][1] = sum1;
	dp[u][0] = sum0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << (dp[1][1] + dp[1][0]) % MOD;
}
