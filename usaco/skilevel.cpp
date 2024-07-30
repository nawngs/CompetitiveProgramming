#include <bits/stdc++.h>

#define name "skilevel"
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
const int N = 500 * 500;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, t, par[N + 3], cnt[N + 3], a[N + 3], sz[N + 3];

struct Edge {
	int u, v, c;
	Edge(int u = 0, int v = 0, int c = 0) : u(u), v (v), c(c) {}
}; 

vector < Edge > e;

int id(int i, int j) {
	return (i - 1) * m + j;
}

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u; sz[u] += sz[v]; cnt[u] += cnt[v];
}

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> t;
	if (t == 1) return cout << 0, 0;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	for (int i = 1; i <= n * m; i++) cin >> cnt[i];
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		if (j < m) e.pb({id(i, j), id(i, j + 1), abs(a[id(i, j)] - a[id(i, j + 1)])});
		if (i < n) e.pb({id(i, j), id(i + 1, j), abs(a[id(i, j)] - a[id(i + 1, j)])});
	}
	sort(e.begin(), e.end(), [&](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	for (int i = 1; i <= n * m; i++) par[i] = i, sz[i] = 1;
	ll res = 0;
	for (auto ed : e) {
		join(ed.u, ed.v);
		int u = find(ed.u);
		if (sz[u] >= t) {
			res += 1ll * cnt[u] * ed.c;
			cnt[u] = 0;
		}
	}
	cout << res;
}