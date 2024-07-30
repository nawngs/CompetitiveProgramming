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
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[2003][203], pre[2003][203], suf[2003][203], d[4003][4003];

vector < pii > adj[4003];

void dijkstra(int st) {
	for (int i = 1; i <= 2 * NMAX; i++) d[st][i] = INF;
	d[st][st] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[st][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[st][v.fi] > u.fi + v.se) {
				d[st][v.fi] = u.fi + v.se;
				heap.push({u.fi + v.se, v.fi});
			}
 		}
	}
}

ll get(int pos, int desx, int desy) {
	return min(d[pos][desx] + pre[desx][desy] - a[desx][1], d[pos][desx + n] + suf[desx][desy] - a[desx][m]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
		for (int j = 1; j <= m; j++) pre[i][j] = pre[i][j - 1] + a[i][j];
		for (int j = m; j >= 1; j--) suf[i][j] = suf[i][j + 1] + a[i][j];
	}
	for (int i = 1; i <= n; i++) {
		adj[i].pb({i + n, pre[i][m] - a[i][1]});
		adj[n + i].pb({i, pre[i][m] - a[i][m]});
		if (i < n) {
			adj[i].pb({i + 1, a[i + 1][1]});
			adj[i + 1].pb({i, a[i][1]});
			adj[n + i].pb({n + i + 1, a[i + 1][m]});
			adj[n + i + 1].pb({n + i, a[i][m]});
		}
	}
	for (int i = 1; i <= n; i++) dijkstra(i), dijkstra(i + n);
	int q; cin >> q;
	int curx = 1, cury = 1;
	ll res = a[1][1];
	while (q--) {
		int x, y; cin >> x >> y;
		ll ans = min(get(curx, x, y) + pre[curx][cury - 1], get(curx + n, x, y) + suf[curx][cury + 1]);
		if (x == curx) ans = min(ans, 1ll * pre[x][max(cury, y)] - 1ll * pre[x][min(cury, y) - 1] - a[curx][cury]);
		res += ans;
		curx = x, cury = y;
	}
	cout << res;
}