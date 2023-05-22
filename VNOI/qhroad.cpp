#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int u, v;
	Edge(int _u, int _v) : u(_u), v(_v) {};
};

struct Dsu {
	vector < int > par;
	
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i; 
	}

	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}

	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}

} dsu;

int n, m, q, res[100005], query[100005];

bool check[100005];

vector < int > adj[100005];

vector < Edge > edges;

void sol() {
	cin >> n >> m >> q;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}
	for (int i = 1; i <= q; i++) {
		cin >> query[i];
		check[query[i] - 1] = true;
	}
	int ans = n;
	for (int i = 0; i < m; i++) {
		auto e = edges[i];
		if (check[i]) continue;
		if (dsu.join(e.u, e.v)) ans --;
	}
	res[q] = ans;
	for (int i = q; i > 1; i--) {
		auto e = edges[query[i] - 1];
		if (dsu.join(e.u, e.v)) ans --;
		res[i - 1] = ans;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
