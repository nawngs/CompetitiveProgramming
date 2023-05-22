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

int n, dp[300003][3];

string a;

vector < int > adj[300003];

void dfs(int u, int e) {
	dp[u][0] = (a[u] == '1');
	dp[u][1] = (a[u] == '0');
	dp[u][2] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		dp[u][0] += min(dp[v][0], min(dp[v][1] + 1, dp[v][2]));
		dp[u][1] += min(dp[v][1], min(dp[v][0] + 1, dp[v][2]));
		dp[u][2] += min(dp[v][2], min(dp[v][1], dp[v][0]) + 1);
	}
	dp[u][2] = min(dp[u][2], min(dp[u][0], dp[u][1]) + 1);
}

int main() {
	fast;
	cin >> n >> a;
	a = ' ' + a;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << dp[1][2];
}
