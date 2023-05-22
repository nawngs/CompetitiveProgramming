#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "mq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
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
	int u, v, c, id;
	Edge(int _u, int _v, int _c, int _id) : u(_u), v(_v), c(_c), id(_id){};
};

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n + 2, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_v == root_u) return false;
		par[root_v] = root_u;
		return true;
	}
} dsu;

int n, m, q, res = 0;

vector < Edge > edges;

vector < int > temp;

set < pii > ms;

int main() {
	fast;
	fre();
	cin >> n >> m >> q;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c, i});
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y){
		return x.c < y.c;
	});
	for (int i = 0; i < m; i++) edges[i].id = i;
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		temp.push_back(e.id);
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			ms.insert({u, v});
		}
		if (type == 2) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			ms.erase({u, v});
		} 
		if (type == 3) {
			res = 0;
			dsu.init(n);
			for (auto x : ms) dsu.join(x.fi, x.se);
			for (auto id : temp) if (dsu.join(edges[id].u, edges[id].v)) res += edges[id].c;
			cout << res << '\n';
		}
	}
}
