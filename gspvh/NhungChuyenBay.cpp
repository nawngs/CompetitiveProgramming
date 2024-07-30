//[FINISHED]
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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k;

vector < pll > adj[NMAX + 3];

ll d[NMAX + 3], g[NMAX + 3];

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

void dijkstra() {
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= k; j++) d[i] = LINF;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	d[1] = 0;
	heap.push({0, 1});
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) if (minimize(d[v.fi], u.fi + v.se)) heap.push({d[v.fi], v.fi});
	}
	for (int t = 1; t <= k; t++) {
		for (int i = 1; i <= n; i++) g[i] = LINF;
		for (int i = 1; i <= n; i++) for (auto v : adj[i]) minimize(g[v.fi], d[i] - v.se);
		for (int i = 1; i <= n; i++) {
			d[i] = min(d[i], g[i]);
			heap.push({d[i], i});
		}
		while (!heap.empty()) {
			auto u = heap.top(); heap.pop();
			if (u.fi != d[u.se]) continue;
			for (auto v : adj[u.se]) if (minimize(d[v.fi], u.fi + v.se)) heap.push({d[v.fi], v.fi});
		}
	}
	cout << d[n] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c});
	}
	dijkstra();
}