#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, x, y, f[200005], cnt_ance[200005], ans, cnt = -1, maxx;

vector < int > adj[200005];

void dfs(int u, int e) {
	if (u == y) cnt_ance[u] = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		if (cnt_ance[v] != -1) cnt_ance[u] = cnt_ance[v] + 1;
		else f[u] = max(f[u], f[v] + 1);
	}
}

void dfs2(int u, int e) {
	cnt ++;
	int pos = -1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (cnt_ance[v] != -1) {
			pos = v;
			break;
		}
	}
	if (pos == -1) return ;
	maxx = max(maxx, cnt + f[u]);
	int maxy = cnt_ance[pos] + f[pos];
	//cout << u << " " << maxx << " " << maxy << '\n';
	ans = max(ans, min(maxx, maxy));
	dfs2(pos, u);
}

int main() {
	slow;
	memset(cnt_ance, 255, sizeof(cnt_ance));
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> x >> y;
	dfs(x, 0);
	maxx = f[x];
	dfs2(x, 0);
	cout << ans + 1;
}
