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

ll n, par[300005][20], h[300005], s[300005][20], log2_n;

vector < pll > adj[300005];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == par[u][0]) continue;
		par[v.fi][0] = u;
		s[v.fi][0] = v.se;
		dfs(v.fi);
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= log2_n; j++) {
			par[i][j] = -1;
			s[i][j] = 0;
		}
	}

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] != 0) s[i][j] = s[i][j - 1] + s[par[i][j - 1]][j - 1];
			//cout << i << " " << j << " " << p[i][j] << '\n';
		}

	}
}

ll LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	ll res = 0;

	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	res += s[v][j];
			 	v = par[v][j];
			 }
		} 
	}

	if (u == v) return res;

	for (int j = log2_n; j >= 0; j --) {
		if (par[u][j] != 0  && par[u][j] != par[v][j]) {
			res += s[v][j] + s[u][j];
			u = par[u][j];
			v = par[v][j];
		}
	}
	return res + s[u][0] + s[v][0];
}

void sol() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dfs(1);
	init();
	int q;
	cin >> q;
	while (q --) {
		int u, v;
		cin >> u >> v;
		auto tam = LCA(u,v);
		cout << tam << '\n';
	}	
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	sol();
}
