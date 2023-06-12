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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], c[100003], f[nmax + 3];

ll ans = 0;

map < int, ll > dp[100003], g[100003];

vector < int > adj[100003];

void sieve() {
	for (int i = 1; i <= nmax; i++) 
		f[i] = i;
	for (int i = 2; i <= nmax; i++)
		if (f[i] == i) 
			for (int j = i * 2; j <= nmax; j+=i) 
				f[j] = i;
}

void dfs(int u, int e) {
	vector < int > temp;
	int x = c[u];
	while (x > 1) {
		if (!temp.size() || temp.back() != f[x]) 
			temp.push_back(f[x]);
		x /= f[x];
	}
	for (auto x : temp) 
		dp[u][x] = g[u][x] = a[u];
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		for (auto x : temp) {
			if (c[v] % x != 0) continue;
			ans = max(ans, dp[u][x] + 2 * g[v][x]);
			ans = max(ans, dp[v][x] + 2 * g[u][x]);
			dp[u][x] = max(dp[u][x], dp[v][x] + 2 * a[u]);
			dp[u][x] = max(dp[u][x], 2 * (g[u][x] + g[v][x] + a[u]) - a[u]);
			g[u][x] = max(g[u][x], g[v][x] + a[u]);
		}
	}
	// cout << u << '\n';
	// for (auto x : temp) {
	// 	cout << x << " " << dp[u][x] << " " << g[u][x] << '\n';
	// }
}

int main() {
	fast;
	cin >> n;
	sieve();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans;
}
