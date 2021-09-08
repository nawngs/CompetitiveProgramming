#include <bits/stdc++.h>

using namespace std;

int n, f[200005], g[200005];

vector < int > adj[200005];

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		f[u] += max(f[v], g[v]);
	}
	for (auto v : adj[u]) {
		if (v == e) continue;
		g[u] = max(g[u], f[u] - max(f[v], g[v]) + 1 + f[v]);
	}
	//cout << u << " " << f[u] << " " << g[u] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("ColorEdge.Inp", "r", stdin);
	freopen("ColorEdge.Out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << max(g[1], f[1]);
}