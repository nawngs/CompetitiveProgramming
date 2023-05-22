#include <bits/stdc++.h>

#define int ll
#define name "danang"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < pll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, d;

vector < pll > adj[200003];

void dijkstra(int s) {
	priority_queue < plll, vector < plll >, greater < plll > > heap; 
	heap.push({{0, s}, -LINF});
	while (sz(heap)) {
		auto x = heap.top(); heap.pop();
		ll val = x.fi.fi, pre = x.se; int u = x.fi.se;
		if (u == n) {
			cout << val << '\n';
			return ;
		}
		while (sz(adj[u])) {
			if (pre + d > adj[u].back().fi) break;
			heap.push({{val + adj[u].back().fi, adj[u].back().se}, adj[u].back().fi});
			adj[u].pop_back();
		}
	}
	cout << -1;
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({c, v}); adj[v].push_back({c, u});
	}
	for (int i = 1; i <= n; i++) 
		sort(adj[i].begin(), adj[i].end());
	dijkstra(1);
}