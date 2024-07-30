//[FINISHED]
#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < ll, pll >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E15;
const int NMAX = 800;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, p, dis[NMAX + 3][NMAX + 3], a[NMAX + 3];

pll d[NMAX + 3];

vector < pll > adj[NMAX + 3];

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) dis[st][i] = LINF;
	dis[st][st] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != dis[st][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dis[st][v.fi] > u.fi + v.se) {
				dis[st][v.fi] = u.fi + v.se;
				heap.push({u.fi + v.se, v.fi});
			}
		}
	}	
}

void dijkstra() {
	for (int i = 1; i <= n; i++) d[i] = {LINF, -LINF};
	d[1] = {0, p};
	priority_queue < plll, vector < plll >, greater < plll > > heap;
	heap.push({0, {1, p}});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.se.fi == n) {
			cout << u.fi << '\n';
			return ;
		}
		if (d[u.se.fi] != mp(u.fi, u.se.se)) continue;
		for (int i = 1; i <= n; i++) if (i != u.se.fi && dis[u.se.fi][i] != LINF) {
			ll v = max(0ll, (dis[u.se.fi][i] - u.se.se + a[u.se.fi] - 1) / a[u.se.fi]);
			ll nxtp = u.se.se + v * a[u.se.fi] - dis[u.se.fi][i];
			if (d[i].fi > u.fi + v) {
				d[i] = mp(u.fi + v, nxtp);
				heap.push({u.fi + v, {i, nxtp}});
			}
			else if (d[i].fi == u.fi + v && d[i].se < nxtp) {
				d[i] = mp(u.fi + v, nxtp);
				heap.push({u.fi + v, {i, nxtp}});
			}
		}
 	}
 	cout << -1 << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> p;
	int O; cin >> O;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c});
	}
	
	for (int i = 1; i <= n; i++) dijkstra(i);
	
	dijkstra();
}