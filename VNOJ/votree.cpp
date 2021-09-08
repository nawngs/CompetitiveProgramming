#include <bits/stdc++.h>

using namespace std;

int n, par[70005][22], h[70005], log2_n, ance[70005][22], q;

vector < int > adj[70005]; 

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) par[i][j] = 0;

	for (int j = 1; j <= log2_n; j++) 
		for (int i = 1; i <= n; i++) 
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) 
			if (h[par[v][j]] >= h[u]) v = par[v][j];
		
	}
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j --) {
		if (par[u][j] != 0  && par[u][j] != par[v][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	cin >> n >> q;
	log2_n = log2(n) + 1; 
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	init();
	//cout << lca(4, 5) << '\n';
	for (int i = 1; i <= n; i++) ance[i][0] = i;
	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			//cout << ance[i - 1][j - 1] << " " << ance[i - 1 + (2 << (j - 1))][j - 1] << '\n';
			if (i + (1 << j) - 1 > n) break;
			ance[i][j] = lca(ance[i][j - 1], ance[i + (1 << (j - 1))][j - 1]);
			//cout << i << " " << j << " " << ance[i][j] << '\n';
		}
	}
	while (q --) {
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		//cout << ance[l][k] << " " <<  << '\n';
		cout << lca(ance[l][k], ance[r - (1 << k) + 1][k]) << '\n';
	}
}
