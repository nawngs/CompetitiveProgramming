#include <bits/stdc++.h>

#define name "path"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
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

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

ll n, m, W, na, nb, par[100003], cnta[100003], cntb[100003], res = 0;

vector < Edge > edges;

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

void join(int u, int v, bool correct) {
	u = find(u); v = find(v);
	if (u == v) return ;
	if (correct) res += cnta[u] * cntb[v] + cntb[u] * cnta[v];
	par[v] = u;
	cnta[u] += cnta[v];
	cntb[u] += cntb[v];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> W >> na >> nb;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.push_back({u, v, c});
	}
	sort(edges.begin(), edges.end(), [](Edge & x, Edge & y){
		return x.c < y.c;
	});
	while (na --) {
		int x; cin >> x; cnta[x] ++;
	}
	while (nb --) {
		int x; cin >> x; cntb[x] ++;
	}
	for (auto e : edges) {
		join(e.u, e.v, (e.c == W));
	}
	cout << res;
}