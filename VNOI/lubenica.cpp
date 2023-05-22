#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int INF = 1E9 + 7;

int n, par[100005][18], h[100005], maxa[100005][18], mina[100005][18], log2_n;

vector < pair < int, int > > adj[100005];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == par[u][0]) continue;
		par[v.fi][0] = u;
		maxa[v.fi][0] = v.se;
		mina[v.fi][0] = v.se;
		dfs(v.fi);
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= log2_n; j++) {
			par[i][j] = -1;
			maxa[i][j] = -INF;
			mina[i][j] = INF;
		}
	}

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] != 0) {
				mina[i][j] = min(mina[i][j], min(mina[i][j - 1], mina[par[i][j - 1]][j - 1]));
				maxa[i][j] = max(maxa[i][j], max(maxa[i][j - 1], maxa[par[i][j - 1]][j - 1]));
			}
			//cout << i << " " << j << " " << p[i][j] << '\n';
		}

	}
}

pair < int, int > LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	int res1 = INF, res2 = -INF;

	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	res1 = min(res1, mina[v][j]);
			 	res2 = max(res2, maxa[v][j]);
			 	v = par[v][j];
			 }
		} 
	}

	if (u == v) return {res1, res2};

	for (int j = log2_n; j >= 0; j --) {
		if (par[u][j] != 0  && par[u][j] != par[v][j]) {
			res1 = min(res1, min(mina[v][j], mina[u][j]));
			res2 = max(res2, max(maxa[v][j], maxa[u][j]));
			u = par[u][j];
			v = par[v][j];
		}
	}
	return {min(res1, min(mina[v][0], mina[u][0])), max(res2, max(maxa[v][0], maxa[u][0]))};
}

int main() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dfs(1);
	init();
	int q;
	cin >> q;
	while (q --) {
		int u, v;
		cin >> u >> v;
		auto tam = LCA(u, v);
		cout << tam.fi << " " << tam.se << '\n';
	}
}
