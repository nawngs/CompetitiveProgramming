#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, f[100005], vs[100005], d[100005];

vector < int > adj[100005];

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (vs[v] && d[v]) continue;
		//cout << u << " " << v << '\n';
		dfs(v);
	}
	f[u] = ++ cnt;
	d[u] = 1; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SORTTOPO.inp", "r", stdin);
	freopen("SORTTOPO.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i);
	for (int i = 1; i <= n; i++) cout << f[i] << '\n';
}