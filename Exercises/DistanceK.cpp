#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;

long long ans = 0;

vector < int > adj[1005];

void dfs(int u, int e) {
	if (e == 0) cnt = 0;
	else cnt ++;
	if (cnt > k) {
		cnt --;
		return ;
	}
	if (cnt == k) ans ++;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
	cnt --;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DistanceK.Inp", "r", stdin);
	freopen("DistanceK.Out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) dfs(i, 0);
	cout << ans / 2;
}