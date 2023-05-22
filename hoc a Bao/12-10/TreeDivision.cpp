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
const int INF = 1e9 + 7;
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

int n, a[100003], dp[100003][2];

vector < int > adj[100003];

void dfs(int u, int e) {
	dp[u][0] = -INF;
	dp[u][1] = INF;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		dp[u][0] = max(dp[u][0], min((a[u] < a[v] ? dp[v][0] : INF), (a[u] < dp[v][1] ? a[v] : INF)));
		dp[u][1] = min(dp[u][1], max((a[u] > a[v] ? dp[v][1] : INF), (a[u] > dp[v][0] ? a[v] : INF)));
	}
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << (dp[1][0] == INF && dp[1][1] == -INF ? "NO" : "YES") << '\n';
}
