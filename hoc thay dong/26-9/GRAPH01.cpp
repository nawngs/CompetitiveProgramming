#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "GRAPH01";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
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

int n, m, a[1000003], dp[1000003][2];

vector < pii > adj[1000003];

void dijkstra() {
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 2; i <= n; i++) 
		dp[i][0] = dp[i][1] = INF;
	dp[1][0] = dp[1][1] = a[1];
	heap.push({a[1], {1, 0}});
	heap.push({a[1], {1, 1}});
	while (heap.size()) {
		auto x = heap.top();
		heap.pop();
		int c = x.fi, u = x.se.fi, pre = x.se.se;
		if (c != dp[u][pre]) continue;
		for (auto v : adj[u]) {
			if ((pre ^ a[u]) == v.se) {
				if (dp[v.fi][v.se] > c + v.se + a[v.fi]) {
					dp[v.fi][v.se] = c + v.se + a[v.fi];
					heap.push({dp[v.fi][v.se], {v.fi, v.se}});
				}
			}
		}
	}
	int res = min(dp[n][0], dp[n][1]);
	cout << (res == INF ? -1 : res) << '\n';
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dijkstra();
}
