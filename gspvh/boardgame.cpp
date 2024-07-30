//[FINISHED]
#include <bits/stdc++.h>

#define name "boardgame"
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
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges;

int par[NMAX + 3], r, c;

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> r >> c;
	for (int i = 1; i <= r + c; i++) 
		par[i] = i;
	for (int i = 1; i <= r; i++)
	for (int j = 1; j <= c; j++) {
		int c; cin >> c;
		edges.pb({i, r + j, c});
	}
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	ll res = 0;
	for (auto e : edges) 
		if (join(e.u, e.v)) res += 1ll * e.c;
	cout << res;
}