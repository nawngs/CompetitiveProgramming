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

const string NAME = "gift";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, m, adj[103][103], f[103][103][103][103];

int dp(int l, int r, int cur, int t) {
	if (f[l][r][cur][t] != -1) return f[l][r][cur][t];
	if (t == 1) {
		f[l][r][cur][t] = 0;
		return 0;
	}
	int res = INF;
	for (int i = l + 1; i < r; i++) {
		if (adj[cur][i]) {
			int newl = l;
			int newr = r;
			if (i < cur) newr = cur; 
			else newl = cur;
			res = min(res, adj[cur][i] + dp(newl, newr, i, t - 1));
		}
	}
	f[l][r][cur][t] = res;
	return res;
}

void sol() {
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = c;
		adj[v][u] = c;
	}
	memset(f, 255, sizeof(f));
	int ans = INF;
	for (int i = 1; i <= n; i++) ans = min(ans, dp(0, n + 1, i, k));
	cout << (ans == INF ? -1 : ans);
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
