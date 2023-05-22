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

int n, x, y, cnt[300003], dist[300003], dem = -1, ans = 0, distx = 0;

vector < int > adj[300003];

void dfs(int u, int e) {
	if (u == y) cnt[u] = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		if (cnt[v] != -1) cnt[u] = cnt[v] + 1;
		else dist[u] = max(dist[u], dist[v] + 1);
	}
}

void dfs2(int u, int e) {
	dem ++;
	int ance = -1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (cnt[v] != -1) {
			ance = v;
			break;
		}
	}
	if (ance == -1) return ;
	distx = max(distx, dem + dist[u]);
	int disty = cnt[ance] + dist[ance];
	ans = max(ans, min(distx, disty));
	dfs2(ance, u);
}

void sol() {
	memset(cnt, -1, sizeof(cnt));
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> x >> y;
	dfs(x, 0);
	dfs2(x, 0);
	cout << ans + 1;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
