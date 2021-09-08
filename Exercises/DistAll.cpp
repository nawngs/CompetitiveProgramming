#include <bits/stdc++.h>

using namespace std;

long long n, f[200005], g[200005];

vector < long long > adj[200005];

void update(long long u, long long e) {
	//cout << u << " " << e << " " << sum << " " << cnt << '\n';
	f[u] += f[e] - f[u] - g[u] + n - g[u];
	for (auto v : adj[u]) {
		if (v == e) continue;
		update(v, u);
	}
}

void dfs(long long u, long long e) {
	f[u] = 0;
	g[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		g[u] += g[v];
		f[u] += f[v] + g[v];
	}
	//cout << u << " " << f[u] << " " << g[u] << '\n';
	if(e == 0) {
		for (auto v : adj[u]) {
			if (v == e) continue;
			update(v, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DistAll.inp", "r", stdin);
	freopen("DistAll.out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		long long u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << f[i] << ' ';
}