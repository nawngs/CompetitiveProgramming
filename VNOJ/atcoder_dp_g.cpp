#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se seond
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int n, m, d[100005];

vector < int > adj[100005];

void dfs(int u) {
	if (d[u] != -1) return ;
	d[u] = 0;
	int res = -1;
	for (auto v : adj[u]) {
		dfs(v);
		res = max(res, d[v]);
	}
	d[u] = max(d[u], res + 1);;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int ans = 0;
	memset(d, 255, sizeof(d));
	for (int i = 1; i <= n; i++) {
		dfs(i);
		//cout << i << " " << d[i] << '\n';
		ans = max(ans, d[i]);
	}
	cout << ans;
}
