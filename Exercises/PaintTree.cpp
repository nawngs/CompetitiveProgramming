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

const string NAME = "painttree";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[200003], num[200003], ans;

vector < int > adj[200003];

void dfs1(int u, int e) {
	num[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs1(v, u);
		dp[u] += dp[v];
		num[u] += num[v];
	}
	dp[u] += num[u];
}

void dfs(int u, int e) {
	//cout << u << " " << dp[u] << '\n';
	ans = max(ans, dp[u]);
	for (auto v : adj[u]) {
		if (v == e) continue;
		dp[u] -= dp[v];
		dp[u] -= num[v];
		num[u] -= num[v];
		dp[v] += dp[u];
		dp[v] += num[u];
		num[v] += num[u];
		dfs(v, u);
		dp[v] -= dp[u];
		dp[v] -= num[u];
		num[v] -= num[u];
		dp[u] += dp[v];
		dp[u] += num[v];
		num[u] += num[v];
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	dfs(1, 0);
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
