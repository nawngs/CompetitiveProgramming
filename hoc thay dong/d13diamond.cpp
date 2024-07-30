#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < pll, pll >
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
const int NMAX = 1E3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, s, d, a[NMAX + 3];

pll f[NMAX + 3][NMAX + 3];

vector < pll > adj[NMAX + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> s >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); 
		// adj[v].pb({u, c});
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) f[i][j] = {-LINF, -LINF};
	f[1][1] = {d, s};
	priority_queue < plll > heap; heap.push({f[1][1], {1, 1}});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != f[u.se.fi][u.se.se]) continue;
		// cout << u.se.fi << " " << u.se.se << " " << u.fi.fi << " " << u.se.se << '\n';
		for (auto v : adj[u.se.fi]) {
			int newv = u.se.se;
			if (a[v.fi] > a[u.se.se]) newv = v.fi;
			ll chg = max(0ll, (v.se - u.fi.se + a[u.se.se] - 1) / a[u.se.se]);
			pll val; val = {u.fi.fi - chg, u.fi.se + chg * a[u.se.se] - v.se};
			if (f[v.fi][newv] < val) {
				f[v.fi][newv] = val;
				heap.push({val, {v.fi, newv}});
			}
		}
	}
	ll res = -1;
	for (int i = 1; i <= n; i++) res = max(res, f[n][i].fi);
	cout << res;
}