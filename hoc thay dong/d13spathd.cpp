#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 1e4 + 3;
const ll MOD = 1e9 + 7;
const ll BASE = 100;

int n, m, res[N][N];

bitset < N > adj[N], dis[BASE + 3], vs;

void solve() {
	int u, v; cin >> u >> v;
	cout << res[u][v] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++) adj[i][j] = 1;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u][v] = adj[v][u] = 0;
	}
	memset(res, 255, sizeof(res));
	for (int i = 0; i < n; i++) {
		vs = 0;
		dis[0] = 0;
		dis[0][i] = 1;
		for (int d = 0; d <= BASE; d++) {
			dis[d + 1] = 0;
			dis[d] ^= (dis[d] & vs);
			// cout << i << " " << d << " " << dis[i][d] << '\n';
			for (int p = dis[d]._Find_first(); p < SZE(dis[d]); p = dis[d]._Find_next(p)) {
				//cout << i << " " << p << " " << d << '\n';
				res[i][p] = d;
				dis[d + 1] |= adj[p];
			}
			vs |= dis[d];
		}
	}
	int q; cin >> q;
	while (q--) solve();
}
