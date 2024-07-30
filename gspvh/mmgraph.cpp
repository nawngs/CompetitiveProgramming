#include <bits/stdc++.h>

#define int ll
#define name "mmgraph"
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
const ll LINF = 1E14;
const int NMAX = 500;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, d[NMAX + 3][NMAX + 3], dis[NMAX + 3][NMAX + 3];

pll w[NMAX + 3];

vector < pll > adj[NMAX + 3];

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) d[st][i] = INF;
	d[st][st] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, st});
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[st][u.se]) continue;
		for (auto v : adj[u.se]) if (w[v.fi].fi <= w[st].fi) {
			if (d[st][v.fi] > max(u.fi, v.se)) {
				d[st][v.fi] = max(u.fi, v.se);
				heap.push({d[st][v.fi], v.fi});
			}
		}
	}
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i].fi;
		w[i].se = i;
	}
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) dis[i][j] = LINF;
	
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); adj[v].pb({u, c});
	}
	
	for (int i = 1; i <= n; i++) dijkstra(i);
	
	sort(w + 1, w + n + 1);
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++) if (max(d[w[k].se][w[i].se], d[w[k].se][w[j].se]) != INF)
			dis[w[i].se][w[j].se] = min(dis[w[i].se][w[j].se], max(d[w[k].se][w[i].se], d[w[k].se][w[j].se]) * w[k].fi);
	}
	
	for (int i = 1; i <= n; i++) {
		ll res = 0;
		for (int j = 1; j <= n; j++) res += dis[i][j];
		cout << res << ' ';
	}
}