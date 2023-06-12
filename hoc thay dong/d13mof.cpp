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

const string NAME = "";
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

int n, m, s, t, dp[103][10003];

vector < piii > adj[103];

void dijkstra(int s) {
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 10000; j++) dp[i][j] = INF;
	dp[s][0] = 0;
	heap.push({0, {s, 0}});
	while (heap.size()) {
		auto x = heap.top();
		heap.pop();
		int u = x.se.fi;
		int c = x.se.se;
		int d = x.fi;
		if (dp[u][c] != d) continue;
		for (auto v : adj[u]) {
			if (c + v.se.fi > 10000) continue;
			if (dp[v.fi][c + v.se.fi] > d + v.se.se) {
				dp[v.fi][c + v.se.fi] = d + v.se.se;
				heap.push({dp[v.fi][c + v.se.fi], {v.fi, c + v.se.fi}});
			}
		}
	}
}

int main() {
	fast;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		adj[u].push_back({v, {c, d}});
		adj[v].push_back({u, {c, d}});
	}
	dijkstra(s);
	int res = 0, mind = INF - 1;
	for (int i = 0; i <= 10000; i++) {
		if (dp[t][i] < mind) res ++;
		mind = min(mind, dp[t][i]);
	}
	cout << res;
}
