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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, d[NMAX + 3];

vector < pii > adj[NMAX + 3];

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[st] = 0;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	heap.push({0, st});
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.se] > u.fi + 1) {
				d[v.se] = u.fi + 1;
				heap.push({u.fi + 1, v.se});
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
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({c, v}); adj[v].pb({c, u});
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), greater < pii >());
	dijkstra(n);
	cout << d[1] << '\n';
	set < int > cur, newcur;
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	cur.insert(1);
	int len = d[1] - 1;
	while (1) {
		if (*cur.begin() == n) return 0;
		int nxt = INF;
		for (auto x : cur) 
			if (adj[x].size()) heap.push({adj[x].back().fi, x});
		while (heap.size()) {
			auto u = heap.top(); heap.pop();
			if (u.fi > nxt) break;
			if (d[adj[u.se].back().se] == len) {
				nxt = u.fi;
				newcur.insert(adj[u.se].back().se);
			}
			adj[u.se].pop_back();
			if (adj[u.se].size()) heap.push({adj[u.se].back().fi, u.se});
		}
		cout << nxt << ' ';
		len --;
		cur = newcur; newcur.clear();
		while (heap.size()) heap.pop();
	}
}