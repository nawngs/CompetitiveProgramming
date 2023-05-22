#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "wedding";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, y, ans, f[300003], max_path_x, cnt = 0, h[300003];

vector < int > adj[300003];

void dfs(int u, int e) {
	if (u == y) h[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		if (h[v] != -1) h[u] = h[v] + 1;
		else f[u] = max(f[u], f[v] + 1);
	}
}

void dfs2(int u, int e) {
	cnt ++;
	int pos = -1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (h[v] != -1) {
			pos = v;
			break;
		}
	}
	if (pos == -1) return ;
	max_path_x = max(max_path_x, cnt + f[u]);
	ans = max(ans, min(max_path_x, h[pos] + f[pos]));
	//cout << u << " " << pos << '\n';
	dfs2(pos, u);
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> x >> y;
	memset(h, 255, sizeof(h));
	dfs(x, 0);
	dfs2(x, 0);
	cout << ans;
}
 