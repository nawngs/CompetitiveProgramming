#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, m, p[100005][18], h[100005], log2_n;

vector < int > adj[100005];

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == p[u][0]) continue;
		p[v][0] = u;
		dfs(v);
	}
}

void init_LCA() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= log2_n; j++) {
			p[i][j] = -1;
		}
	}

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);

	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[p[v][j]] >= h[u]) {
			 	v = p[v][j];
			 }
		} 
	}

	if (u == v) return u;

	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0  && p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

int main() {
	fastflow;
	freopen("LCA.INP", "r", stdin);
	freopen("LCA.OUT", "w", stdout);
	cin >> n >> m;
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	init_LCA();
	while(m --) {
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
}
