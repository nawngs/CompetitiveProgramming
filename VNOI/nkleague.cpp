#include <bits/stdc++.h>

using namespace std;

int n, vs[1005];

string s[1005];

vector < int > adj[1005], topo;

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

int main() {
	cin >> n;
	memset(vs, 0, sizeof(vs));
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == '1') adj[j].push_back(i); 
		}
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i);
	for (int i = 0; i < topo.size(); i++) cout << topo[i] << " ";
}