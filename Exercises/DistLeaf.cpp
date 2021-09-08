#include <bits/stdc++.h>
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int t, ans, n;

vector < pii > adj[200005];

vector < int > dp;

void dfs(int u, int e) {
	//cout << u << " " << e << '\n';
	dp[u] = 0;
	int child = 0;
	vector < int > maxdp;
	maxdp.clear();
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);
		child ++;
		maxdp.push_back(dp[v.fi] + v.se);
	}
	sort(maxdp.begin(), maxdp.end());
	if (maxdp.size() >= 2) 
		ans = min(ans, maxdp[0] + maxdp[1]);
	if (e == 0 && child == 1 && maxdp.size()) ans = min(ans, maxdp[0]);
	if (maxdp.size()) dp[u] = maxdp[0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DistLeaf.inp", "r", stdin);
	freopen("DistLeaf.out", "w", stdout);
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i++) adj[i].clear();
		dp.resize(n + 5, 0);
		ans = 1e9 + 7;
		for (int i = 1; i < n; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			adj[u].push_back({v, c});
			adj[v].push_back({u, c});
		}
		dfs(1, 0);
		cout << ans << '\n';
	}
}