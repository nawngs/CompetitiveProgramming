#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, m;

bool vs[100005];

pair < int, int > e[100005];

vector < int > adj[100005];


void dfs(int u, int e) {
	if (vs[u]) return ;
	vs[u] = true;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
}

bool sol(int x) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vs[i] = false;
	}
	for (int i = 1; i <= x; i++) {
		adj[e[i].fi].push_back(e[i].se);
		adj[e[i].se].push_back(e[i].fi);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) if (!vs[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
		cin >> e[i].fi >> e[i].se;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		bool temp = sol(mid);
		if (temp) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}	
	if (ans == -1) cout << "FAILURE";
	else cout << ans;
}