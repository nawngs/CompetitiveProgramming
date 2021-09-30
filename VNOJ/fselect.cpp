#include <bits/stdc++.h>

using namespace std;

int n, root, k, par[200005][19], h[200005], f[200005], maxk[200005], res[200005], log2_n;
vector < int > adj[200005];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	if (h[u] > h[maxk[f[u]]]) maxk[f[u]] = u;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) par[i][j] = 0;

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			//cout << i << " " << j << " " << par[i][j] << '\n';
		}
	}
	
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	//cout << u << " " << v << '\n';
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	cin >> n >> k;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		if (v == 0) root = i;
		else {
			adj[v].push_back(i);
			adj[i].push_back(v);
		}
		f[i] = u;
	}
	dfs(root);
	//cout << "OK" << '\n';
	init();
	for (int i = 1; i <= n; i++) {
		int lca = LCA(i, maxk[f[i]]);
		res[f[i]] = max(res[f[i]], h[i] + h[maxk[f[i]]] - 2 * h[lca]);
		//cout << i << " " << f[i] << " " << res[f[i]] << " " << lca << '\n';
	}
	for (int i = 1; i <= k; i++) cout << res[i] << '\n';
}