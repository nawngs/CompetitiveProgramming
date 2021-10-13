#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, m, dem, f[400005], sum, cnt_scc;

bool vs[400005];

vector < int > adj[400005], scc[400005];

void dfs(int u, int e) {
	f[u] = cnt_scc;
	scc[cnt_scc].push_back(u);
	if (u >= n + 1) dem ++;
	sum ++;
	vs[u] = true;
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(v, u);
	}
}

void sol() {
	cin >> n >> m;
	if (m == 0) {
		cout << n << '\n';
		return ;
	}
	cnt_scc = 0;
	memset(vs, false, sizeof(vs));
	for (int i = 1; i <= 2 * n; i++) {
		adj[i].clear();
		scc[i].clear();
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		string s;
		cin >> u >> v >> s;
		if (s == "imposter") {
			adj[u].push_back(v + n);
			adj[v + n].push_back(u);
			adj[u + n].push_back(v);
			adj[v].push_back(u + n);
		}
		else {
			adj[u].push_back(v);
			adj[v].push_back(u);
			adj[u + n].push_back(v + n);
			adj[v + n].push_back(u + n);
		}
	}
	ll cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (vs[i]) continue;
		if (adj[i].size() == 0) cnt ++;
		else {
			dem = 0;
			sum = 0;
			cnt_scc ++;
			dfs(i, 0);
		}
	}
	int ans = -1;
	for (int i = 1; i <= cnt_scc; i++) {
		bool th = true;
		int dem = 0;
		int tam = scc[i].size();
		for (auto v : scc[i]) {
			//cout << i << " " << v << '\n';
			if (v <= n && f[v] == f[v + n]) {
				th = false;
				break;
			}
			if (v > n) dem ++;
		}
		if (th) ans = max(ans, dem + n - tam);
	}
	cout << ans << '\n';
}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
