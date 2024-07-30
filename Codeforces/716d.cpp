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
const int N = 1e3;
const int M = 1e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, L, s, t, ds[N + 3], dt[N + 3], ru[M + 3], rv[M + 3], rc[M + 3];

vector < pii > adj[N + 3];

vector < int > q[N + 3];

void dijkstra(int st, int d[]) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[st] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	heap.push({0, st});
	while (heap.size()) {
		int dis, u; tie(dis, u) = heap.top(); heap.pop();
		if (dis != d[u]) continue;
		for (auto v : adj[u]) {
			if (d[v.fi] > dis + v.se) {
				d[v.fi] = dis + v.se;
				 heap.push({dis + v.se, v.fi});
			}
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> L >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		if (c == 0) {
			adj[u].pb({v, INF}); adj[v].pb({u, INF});
			q[u].pb(i); q[v].pb(i);
		}
		else adj[u].pb({v, c}), adj[v].pb({u, c});
		ru[i] = u; rv[i] = v; rc[i] = c;
	}
	dijkstra(s, ds);
	if (ds[t] < L) {
		cout << "NO" << '\n';
		return 0;
	}
	dijkstra(t, dt);
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 0; i < n; i++) heap.push({ds[i], i});
	while (heap.size()) {
		int dis, u; tie(dis, u) = heap.top(); heap.pop();
		if (dis != ds[u]) continue;
		if (u == t && dis != L) {
			cout << "NO" << '\n';
			return 0;
		}
		for (auto v : adj[u]) {
			if (ds[v.fi] > dis + v.se) {
				ds[v.fi] = dis + v.se;
				heap.push({dis + v.se, v.fi});
			}
		}
		for (auto id : q[u]) {
			int v = ru[id] ^ rv[id] ^ u;
			if (ds[v] < ds[u]) continue;
			int &c = rc[id];
			c = max(1, L - dt[v] - dis);
			if (ds[v] > dis + c) {
				ds[v] = dis + c;
				heap.push({dis + c, v});
			}
		}
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= m; i++) cout << ru[i] << " " << rv[i] << " " << rc[i] << '\n';
}