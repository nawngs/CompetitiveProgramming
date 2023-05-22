#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define int ll
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};


ll n, a[1000003], par[1000003], sze[1000003];

vector < Edge > edges;

int find_root(int u) {
	if (par[u] == u) return u;
	return par[u] = find_root(par[u]);
}

main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		ll u, v, c; cin >> u >> v;
		c = max(a[u], a[v]);
		edges.push_back({u, v, c});
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sze[i] = 1;
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y){
		return x.c < y.c;
	});
	ll res = 0;
	for (auto &e : edges) {
		int u = e.u, v = e.v, c = e.c;
		u = find_root(u); v = find_root(v);
		if (u == v) continue;
		res += sze[u] * sze[v] * c;
		par[v] = u;
		sze[u] += sze[v];
		e.c = min(a[e.u], a[e.v]);
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sze[i] = 1;
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y){
		return x.c > y.c;
	});
	for (auto e : edges) {
		int u = e.u, v = e.v, c = e.c;
		u = find_root(u); v = find_root(v);
		if (u == v) continue;
		res -= sze[u] * sze[v] * c;
		par[v] = u;
		sze[u] += sze[v];
	}
	cout << res << '\n';
}