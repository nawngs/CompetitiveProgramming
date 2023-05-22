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

int n, m, p[10003], dp[10003][10003];

bool vs[10003], valid[10003][10003];

vector < int > adj[10003], tmp;

void dfs(int u) {
	vs[u] = 1;
	tmp.push_back(u);
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(v);
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			tmp.clear();
			dfs(i);
			for (auto x : tmp) 
				for (auto y : tmp) valid[x][p[y]] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (!valid[i][j]) continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}
// why pending nigga
