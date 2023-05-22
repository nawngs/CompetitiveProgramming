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

const string NAME = "qpath";
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

ll n, m, q, adj[505][505];

pll d[503][503];


int main() {
	fast;
	fre();
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
				continue;
			}
			if (adj[i][j]) {
				d[i][j].fi = adj[i][j];
				d[i][j].se = 1;
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