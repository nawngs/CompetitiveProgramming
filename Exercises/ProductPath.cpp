#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, f[3005];

int l, r;

vector < int > adj[3005];

pair < int, int > edge[3005];

void dfs(int u, int e, int &maxa) {
	f[u] = 0;
	int maxf = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u, maxa);
		maxa = max(maxa, maxf + f[v] + 1);
		maxf = max(maxf, f[v] + 1);
		f[u] = max(f[u], maxf);
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("ProductPath.Inp", "r", stdin);
		freopen("ProductPath.Out", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> edge[i].fi >> edge[i].se;
		adj[edge[i].fi].push_back(edge[i].se);
		adj[edge[i].se].push_back(edge[i].fi);
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		memset(f, 0, sizeof(f));
		l = r = 0;
		dfs(edge[i].fi, edge[i].se, l);
		memset(f, 0, sizeof(f));
		dfs(edge[i].se, edge[i].fi, r);
		ans = max(ans, l * r);
	}
	cout << ans;
}