#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int n, m, p[100005][18], log2_n, root;

vector < int > adj[100005], h;

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == p[u][0]) continue;
		p[v][0] = u;
		dfs(v);
	}
}

void init_LCA() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) p[i][j] = -1;


	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			//cout << i << " " << j << " " << p[i][j] << '\n';
		}

	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);

	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --)
			 if (h[p[v][j]] >= h[u]) v = p[v][j];
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
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin >> n) {
		if (n == 0) break;
		int u, v;
		h.resize(n + 2, 0);
		log2_n = log2(n) + 1;
		root = 1;
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1);
		init_LCA();
		/*for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) cout << i << " " << j << " " << LCA(i, j) << '\n';
		*/
		
		cin >> m;
		while (m --) {
			char s;
			cin >> s;
			if (s == '?') {
				cin >> u >> v;
				int uroot = LCA(u, root);
				int vroot = LCA(v, root);
				int uv = LCA(u, v);
				if (uroot == vroot) cout << uv << '\n';
				else if (uv == uroot) cout << vroot << '\n';
					else cout << uroot << '\n';
			}
			else  cin >> root;
			
		}
	}
}