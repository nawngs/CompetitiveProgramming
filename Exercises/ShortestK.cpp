#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "shortestk";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, dist[73][73][73], adj[73][73];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) {
			adj[i][j] = INF;
			for (int k = 0; k <= n; k++) dist[i][j][k] = INF;
		}
	for (int i = 1; i <= n; i++) {
		dist[i][i][0] = 0;
		adj[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		if (adj[u][v] == -1) adj[u][v] = c;
		else adj[u][v] = min(adj[u][v], c);
		dist[u][v][1] = adj[u][v];
	}
	for (int k = 1; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				 dist[i][j][k] = min(dist[i][j][k], dist[i][j][k - 1]);
				for (int x = 1; x <= n; x++)  dist[i][x][k + 1] = min(dist[i][x][k + 1], dist[i][j][k] + adj[j][x]);
			}
		}
	}
	ll len, q;
	cin >> len >> q;
	len = min(len, n);
	while (q --) {
		int u, v;
		cin >> u >> v;
		cout << (dist[u][v][len] == INF ? -1 : dist[u][v][len]) << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
