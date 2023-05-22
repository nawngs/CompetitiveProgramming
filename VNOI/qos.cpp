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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 2e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, t, k, C, d[1003], dp[1003][103];

vector < pii> adj[1003];

vector < int > path;

void dijkstra() {
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 2; i <= n; i++) d[i] = INF;
	d[1] = 0;
	heap.push({0, 1});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
}

int calc(int u, int diff) {
	if (diff > C) return 0;
	if (dp[u][diff] != -1) return dp[u][diff];
	ll res = (u == t);
	for (auto v : adj[u]) {
		res += calc(v.fi, diff + d[u] + v.se - d[v.fi]);
		if (res > INF) res = INF;
	}
	dp[u][diff] = res;
	return res;
}

void trace(int u, int diff) {
	path.push_back(u);
	if (u == t) k --;
	if (k == 0) return;
	for (auto v : adj[u]) {
		int val = calc(v.fi, diff + d[u] + v.se - d[v.fi]);
		if (val >= k) {
			trace(v.fi, diff + d[u] + v.se - d[v.fi]);
			return ;
		}
		else k -= val;
	}
}

int main() {
	//fast;
	cin >> n >> m >> t >> k;
	C = INF;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		C = min(c, C);
		adj[u].push_back({v, c});
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	dijkstra();
	memset(dp, 255, sizeof(dp));
	if (calc(1, 0) < k) {
		cout << -1 << '\n';
		return 0;
	}

	trace(1, 0);
	cout << path.size() << '\n';
	for (auto x : path) cout << x << " ";
}
