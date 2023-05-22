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

int n, m, q, scc = 0, par[300003], dia[300003], len = 0, final = 0;

vector < int > adj[300003];

void dfs(int u, int e) {
	par[u] = scc;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
}

void dfs(int u, int e, int depth) {
	if (depth > len) {
		len = depth;
		final = u;
	}
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u, depth + 1);
	}
}

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return ;
	par[v] = u;
	dia[u] = max(dia[u], max(dia[v], (dia[u] + 1) / 2 + (dia[v] + 1) / 2 + 1));
}

int main() {
	fast;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(par, 255, sizeof(par));
	for (int i = 1; i <= n; i++) 
		if (par[i] == -1) {
			scc = i;
			dfs(i, 0);
			len = -1;
			dfs(i, 0, 0);
			len = -1;
			dfs(final, 0, 0);
			dia[scc] = len;
		}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			cout << dia[find(x)] << '\n';
		}
		else {
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
	}
}
