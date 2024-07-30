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

ll n, m, k, d[NMAX + 3], f[NMAX + 3];

bool th[NMAX + 3];

vector < int > a, res;

vector < pll > adj[NMAX + 3];

void dijkstra(int st) {
	for (int i = 1; i <= n; i++) d[i] = LINF;
	d[st] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				heap.push({u.fi + v.se, v.fi});
			}
		}
	}
}

void solve(int st) {
	for (int i = 1; i <= n; i++) d[i] = LINF, f[i] = 0;
	d[st] = 0; f[st] = 1;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, st});
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != d[u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[v.fi] > u.fi + v.se) {
				d[v.fi] = u.fi + v.se;
				f[v.fi] = f[u.se] + th[v.fi];
				heap.push({u.fi + v.se, v.fi});
			}
			else if (d[v.fi] == u.fi + v.se) f[v.fi] = max(f[v.fi], f[u.se] + th[v.fi]);
		}
	}
	for (int i = 1; i <= n; i++) if (f[i] == k) res.pb(i);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	a.resize(k);
	for (auto &x : a) {
		cin >> x;
		th[x] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); adj[v].pb({u, c});
	}
	dijkstra(a[0]);
	int head = a[0];
	for (auto x : a) if (d[x] > d[head]) head = x;
	dijkstra(head);
	int tail = head;
	for (auto x : a) if( d[x] > d[tail]) tail = x;
	solve(head); solve(tail);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	cout << SZE(res) << '\n';
	for (auto x : res) cout << x << " ";
}