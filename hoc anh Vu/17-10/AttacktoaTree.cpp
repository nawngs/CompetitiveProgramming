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

ll n, a[5003], dp[5003][5003][2], sze[5003], f[5003][5003][2];

vector < int > adj[5003];

void minimize(ll &x, ll y) {
	x = min(x, y);
}

void dfs(int u, int e) {
	sze[u] = 0;
	dp[u][0][(a[u] < 0)] = a[u];
	for (auto v : adj[u]) {
		if (v == e) continue; 
		dfs(v, u);
		for (int i = sze[u]; i >= 0; i--)
			for (int x = 0; x < 2; x++)
				for (int j = 0; j <= min(sze[v], n - i); j++)
					for (int y = 0; y < 2; y++) {
						if (dp[u][i][x] == LINF || dp[v][j][y] == LINF) continue;
						minimize(f[u][i + j][x || y], dp[u][i][x] + dp[v][j][y]);
						if (dp[v][j][y] < 0 || (y == 0 && dp[v][j][y] < LINF)) {
							minimize(f[u][i + j + 1][x], dp[u][i][x]);
						}
					}
		sze[u] += sze[v] + 1;
		for (int i = 0; i <= sze[u]; i++)
			for (int x = 0; x < 2; x++) 
				dp[u][i][x] = f[u][i][x], f[u][i][x] = LINF;
	}
	// for (int i = 0; i <= sze[u]; i++)
	// 	cout << u << " " << dp[u][i][0] << " " << dp[u][i][1] << '\n';
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
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n; j++) dp[i][j][0] = dp[i][j][1] = f[i][j][0] = f[i][j][1] = LINF;
	dfs(1, 0);
	for (int i = 0; i < n; i++)
		if (dp[1][i][1] < 0 || dp[1][i][0] < LINF) 
			return cout << i, 0;
}
