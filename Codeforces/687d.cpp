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
const int N = 1000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, q, par[N + 3], cost[N + 3], l, r;

struct Edge {
	int u, v, w, id;
	Edge(int u = 0, int v = 0, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
} es[N * N + 3];

int find(int u) {
	if (u == par[u]) return u;
	int ance = find(par[u]);
	cost[u] ^= cost[par[u]];
	par[u] = ance;
	return ance;
}

bool merge(int u, int v) {
	find(u), find(v);
	if (par[u] == par[v] && cost[u] == cost[v]) return false;
	int ance = par[v];
	par[ance] = par[u]; cost[ance] = cost[v] ^ 1 ^ cost[u];
	return true;
}

int solve() {
	cin >> l >> r;
	for (int i = 1; i <= n; i++) par[i] = i, cost[i] = 0;
	for (int i = 1; i <= m; i++) if (l <= es[i].id && es[i].id <= r) 
		if (!merge(es[i].u, es[i].v)) return es[i].w;
	return -1;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> es[i].u >> es[i].v >> es[i].w;
		es[i].id = i;
	}
	sort(es + 1, es + m + 1, [&](Edge &x, Edge &y) {
		return x.w > y.w;
	});
	while (q--) cout << solve() << '\n';
}