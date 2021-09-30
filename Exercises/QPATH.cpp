#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define plll pair < ll, pll >
#define fi first
#define se second

using namespace std;

const ll INF = 1E18;

ll n, m, q, adj[505][505];

pll d[503][503];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("QPATH.INP", "r", stdin);
	freopen("QPATH.OUT", "w", stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = adj[v][u] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				d[i][j].fi = 0;
				d[i][j].se = 0;
				//cout << i << " " << j << " " << d[i][j].fi << '\n';
				continue;
			}
			if (adj[i][j]) {
				d[i][j].fi = adj[i][j];
				d[i][j].se = 1;
				//cout << i << " " << j << " " << d[i][j].fi << '\n';
				continue;
			}
			d[i][j].fi = d[i][j].se = INF;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j].fi > d[i][k].fi + d[k][j].fi) {
					d[i][j].fi = d[i][k].fi + d[k][j].fi;
					d[i][j].se = d[i][k].se + d[k][j].se;
				}
				else if (d[i][j].fi == d[i][k].fi + d[k][j].fi) d[i][j].se = min(d[i][j].se, d[i][k].se + d[k][j].se);
				
			}
		}
	}
	while(q --) {
		ll u, v;
		cin >> u >> v;
		cout << d[u][v].fi << " " << d[u][v].se << '\n';
	}
}