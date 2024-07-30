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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, s;

ll d[9 * N + 3];

vector < pll > adj[9 * N + 3];

void build(int node, int l, int r) {
	if (l == r) {
		adj[node + n].pb({l, 0});
		adj[l].pb({node + 5 * n, 0});
		return ;
	}
	build(lnode); build(rnode);
	int lid = node * 2, rid = node * 2 + 1;
	adj[node + n].pb({lid + n, 0});
	adj[node + n].pb({rid + n, 0});
	adj[lid + 5 * n].pb({node + 5 * n, 0});
	adj[rid + 5 * n].pb({node + 5 * n, 0});
}

void add_to(int node, int l, int r, int u, int v, int from, int w) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		adj[from].pb({node + n, w});
		return ;
	}
	add_to(lnode, u, v, from, w);
	add_to(rnode, u, v, from, w);
}

void add_from(int node, int l, int r, int u, int v, int to, int w) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		adj[node + 5 * n].pb({to, w});
		return ;
	}
	add_from(lnode, u, v, to, w);
	add_from(rnode, u, v, to, w);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q >> s;
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int ope; cin >> ope;
		if (ope == 1) {
			int u, v, w; cin >> u >> v >> w;
			adj[u].pb({v, w});
		}
		if (ope == 2) {
			int v, l, r, w; cin >> v >> l >> r >> w;
			add_to(1, 1, n, l, r, v, w);
		}
		if (ope == 3) {
			int v, l, r, w; cin >> v >> l >> r >> w;
			add_from(1, 1, n, l, r, v, w);
		}
	}
	for (int i = 1; i <= 9 * n; i++) d[i] = LINF;
	d[s] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	heap.push({0, s});
	while (!heap.empty()) {
		ll val, u; tie(val, u) = heap.top(); heap.pop();
		if (val != d[u]) continue;
		// cout << u << " " << val << '\n';
		for (auto v : adj[u]) {
			if (d[v.fi] > val + v.se) {
				d[v.fi] = val + v.se;
				heap.push({d[v.fi], v.fi});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << (d[i] == LINF ? -1 : d[i]) << " ";
}