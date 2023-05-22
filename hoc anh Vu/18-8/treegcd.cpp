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

const string NAME = "treegcd";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, dp[103][10003], f[103][10003];

vector < int > adj[103], prime[10003];

vector < pii > val[10003];

void dfs(int u, int e) {
	bool leaf = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		leaf = 0;
		dfs(v, u);
	}
	if (leaf) for (int i = 1; i <= m; i++) dp[u][i] = 1;
	else {
		for (int i = 1; i <= m; i++) {
			dp[u][i] = 1;
			for (auto v : adj[u]) {
				if (v == e) continue;
				ll tam = 0;
				for (auto x : val[i]) {
					if (x.se % 2 == 1) tam = (tam + f[v][x.fi]) % MOD;
					else tam = (tam - f[v][x.fi] + MOD) % MOD;
				}
				dp[u][i] = (dp[u][i] * tam) % MOD;
			}
		}
	}
	for (int i = 1; i <= m; i++) 
		for (int j = i; j <= m; j+=i) f[u][i] = (f[u][i] + dp[u][j]) % MOD;
	//for (int i = 1; i <= m; i++) cout << u << " " << i << " " << dp[u][i] << '\n';
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) {
		int x = i;
		for (int j = 2; j * j <= i; j++) {
			if (x % j == 0) {
				prime[i].push_back(j);
				while (x % j == 0) x /= j;
			}
		}
		if (x != 1) prime[i].push_back(x);
		for (int mask = 1; mask < (1 << prime[i].size()); mask++) {
			int temp = 1;
			for (int bit = 0; bit < prime[i].size(); bit++) if (mask & (1 << bit)) temp *= prime[i][bit];
			val[i].push_back({temp, __builtin_popcount(mask)});
		}
	}
	dfs(1, 0);
	ll res = 0;
	for (int i = 1; i <= m; i++) res = (res + dp[1][i]) % MOD;
	cout << res;
}
