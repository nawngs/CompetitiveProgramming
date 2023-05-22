#include <bits/stdc++.h>

#define name "test"
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
const ll LINF = 9E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Edge {
	ll u, v, d, w;
	Edge(ll _u, ll _v, ll _d, ll _w) {
		u = _u, v = _v, d = _d, w = _w;
	}
};

ll n, m, d[20003], w[20003], c1, c2;

bool vs[1003];

vector < Edge > edges;

int par[20003];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	par[v] = u; return true;
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> c1 >> c2;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v >> d[i] >> w[i];
		edges.pb({u, v, d[i], w[i]});
	}
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.d < y.d;
	});
	clock_t start, end;   
    double time_use;     
    start = clock();
	ll res = LINF;
	vector < Edge > mst, new_mst;
	for (auto e : edges) {
		mst.pb(e);
		for (int i = 1; i <= n; i++)
			par[i] = i;
		int scc = n;
		sort(mst.begin(), mst.end(), [&](Edge &x, Edge &y) {
			return x.w < y.w;
		});
		new_mst.clear();
		ll maxw = 0;
		for (auto ee : mst) {
			if (join(ee.u, ee.v)) {
				scc --; maxw = max(maxw, ee.w);
				new_mst.pb(ee);
			}
		}
		if (scc == 1) res = min(res, e.d * c1 + maxw * c2);
		mst = new_mst;
	}
	cout << (res == LINF ? -1 : res) << '\n';;
	end = clock();
	time_use = double(end - start) / CLOCKS_PER_SEC;
	cerr << time_use << '\n';
}