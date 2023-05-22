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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, w, b, g[5003][5003], f[5003][5003];

vector < int > adj[5003], adj_rev[5003];


void dfs(int u, int v) {
	if (g[u][v] != -1) return ;
	g[u][v] = 0;
	for (auto x : adj[u]) {
		dfs(x, v);
		g[u][v] |= !g[x][v];
	}
	for (auto x : adj_rev[v]) {
		dfs(u, x);
		g[u][v] |= !g[u][x];
	}
}

int get(int u, int v) {
	if (f[u][v] != -1) return f[u][v];
	int len;
	if (g[u][v] == 1) len = INF;
	else len = 0;
	for (auto x : adj[u]) {
		if (g[x][v] != g[u][v]) {
			if (g[u][v] == 1) len = min(len, get(x, v) + 1);
			else len = max(len, get(x, v) + 1);
		}
	}
	for (auto x : adj_rev[v]) {
		if (g[u][x] != g[u][v]) {
			if (g[u][v] == 1) len = min(len, get(u, x) + 1);
			else len = max(len, get(u, x) + 1);
		}
	}
	f[u][v] = len;
	return len;
}

int main() {
	fast;
	cin >> n >> m >> w >> b;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
	}
	memset(g, 255, sizeof(g));
	memset(f, 255, sizeof(f));
	dfs(w, b);
	cout << get(w, b);
}
