#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

struct Edges {
	int v, c1, c2;
	Edges(int _v, int _c1, int _c2) : v(_v), c1(_c1), c2(_c2){};
};

int n, p[200005][20], log2_n, h[200005], cnt[200005][20]; 

pair < int, int > val[200005];

vector < Edges > adj[200005];

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.v == p[u][0]) continue;
		p[v.v][0] = u;
		val[v.v].fi = v.c1;
		val[v.v].se = v.c2;
		dfs(v.v);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) p[i][j] = -1;

	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
}

void LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[p[v][j]] >= h[u]) {
			 	cnt[v][j] ++;
			 	v = p[v][j];
			 }
		} 
	}
	if (u == v) return ;
	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0  && p[u][j] != p[v][j]) {
			cnt[u][j] ++;
			cnt[v][j] ++;
			u = p[u][j];
			v = p[v][j];
		}
	}
	cnt[u][0] ++;
	cnt[v][0] ++;
	return ;
}

int main() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v, c1, c2;
		cin >> u >> v >> c1 >> c2;
		adj[u].push_back({v, c1, c2});
		adj[v].push_back({u, c1, c2});
	}
	dfs(1);
	init();
	for (int i = 1; i < n; i++) LCA(i, i + 1);
	for (int j = log2_n; j >= 1; j --) {
		for (int i = 1; i <= n; i++) {
			cnt[i][j - 1] += cnt[i][j];
			cnt[p[i][j - 1]][j - 1] += cnt[i][j];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (1ll * val[i].fi * cnt[i][0] > val[i].se) ans += val[i].se;
		else ans += 1ll * val[i].fi * cnt[i][0];
	}
	cout << ans;
}