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

const string NAME = "rbtree";
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

int n, c[nmax + 3], id_comp[nmax + 3], num_comp = 0, comp_color[nmax + 3];

vector < int > adj[nmax + 3], g[nmax + 3], comp[nmax + 3];

int dp[nmax + 3];

pii ans;

void dfs(int u, int e) {
	comp[num_comp].push_back(u);
	id_comp[u] = num_comp;
	for (auto v : adj[u]) {
		if (v == e || c[v] != c[u]) continue;
		dfs(v, u);
	}
}

void calc(int u, int e) {
	if (dp[u] > ans.fi) 
		ans = {dp[u], u};
	for (auto v : g[u]) {
		if (v == e) continue;
		dp[v] = dp[u] + 1;
		calc(v, u);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		id_comp[i] = -1;
		adj[i].clear();
		g[i].clear();
		comp[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	num_comp = 0;
	for (int i = 1; i <= n; i++) 
		if (id_comp[i] == -1) {
			comp_color[++ num_comp] = c[i];
			dfs(i, 0);
		}
	for (int i = 1; i <= num_comp; i++) {
		for (auto u : comp[i]) {
			for (auto v : adj[u]) 
				if (c[v] != c[u])
					g[i].push_back(id_comp[v]);
		}
	}
	dp[1] = 1;
	ans = {1, 1};
	calc(1, 0);
	dp[ans.se] = 1;
	calc(ans.se, 0);
	cout << ans.fi / 2 << ' ';
	
}

int main() {
	fast;
	//fre();
	int O; cin >> O;
	int t = 1; cin >> t;
	while (t --) sol();
}
