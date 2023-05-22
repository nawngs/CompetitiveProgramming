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

ll n, M, dp[100003], f[100003];

vector < int > adj[100003];

void dfs1(int u, int e) {
	dp[u] = 1;
	f[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs1(v, u);
		dp[u] = (dp[u] * (f[v] + 1)) % M;
		f[u] = (f[u] + f[v]) % M;
	}
}

void dfs2(int u, int e) {
	if (e != 0) {
		
	}
	for(auto v : adj[u]) {
		if (v == e) continue;
		dfs2(v, u);
	}
}

void sol() {
	cin >> n >> M;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) cout << dp[i] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
