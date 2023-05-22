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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, dp[50003][503], ans = 0;

vector < int > adj[50003];

void dfs(int u, int e) {
	dp[u][0] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		for (int i = 1; i <= k; i++) dp[u][i] += dp[v][i - 1];
	}
	ans += dp[u][k];
	for (auto v : adj[u]) {
		if (v == e) continue;
		for (int i = 1; i <= k; i++) dp[u][i] -= dp[v][i - 1];
		for (int i = 0; i <= k - 2; i++) ans += dp[v][i] * dp[u][k - 1 - i];
	}
	for (auto v : adj[u]) {
		if (v == e) continue;
		for (int i = 1; i <= k; i++) dp[u][i] += dp[v][i - 1];
	}
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
