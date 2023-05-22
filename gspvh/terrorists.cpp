#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "terrorists";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1000500000 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n  + 5, 0);
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_v = find_root(v);
		int root_u = find_root(u);
		if (root_u == root_v) return false;
		par[root_u] = root_v;
		return true;
	}
} dsu;

struct Edge {
	int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

vector < Edge > edges, forgo;

int n, m, q, par[100001][18], h[100001], s[100001][18], log2_n, val[104], num[100001], stt = 0, d[104][100001], cin_u, cin_v, cin_c, res, res_LCA;

bool valid[100001];

vector < pii > adj[100001];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == par[u][0]) continue;
		par[v.fi][0] = u;
		s[v.fi][0] = v.se;	
		dfs(v.fi);
	}
}

void init() {
	for (int j = 1; j <= log2_n; ++j) {
		for (int i = 1; i <= n; ++i) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] != 0) s[i][j] = s[i][j - 1] + s[par[i][j - 1]][j - 1];
		}
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	res_LCA = 0;
	log2_n = log2(h[v]);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; --j) {
			 if (h[par[v][j]] >= h[u]) {
			 	res_LCA += s[v][j];
			 	v = par[v][j];
			 }
		} 
	}

	if (u == v) return res_LCA;

	for (int j = log2_n; j >= 0; --j) {
		if (par[u][j] != 0  && par[u][j] != par[v][j]) {
			res_LCA += s[v][j] + s[u][j];
			u = par[u][j];
			v = par[v][j];
		}
	}
	return res_LCA + s[u][0] + s[v][0];
}

void dijkstra(int pos) {
	priority_queue < pii, vector < pii > , greater < pii > > heap;
	for (int i = 1; i <= n; ++i) d[pos][i] = INF;
	d[pos][val[pos]] = 0;
	heap.push({d[pos][val[pos]], val[pos]});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != d[pos][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (d[pos][v.fi] > u.fi + v.se) {
				d[pos][v.fi] = u.fi + v.se;
				heap.push({d[pos][v.fi], v.fi});
			}
		}
	}
}

void sol() {
	cin >> n >> m >> q;
	stt = 0;
	log2_n = log2(n);
	dsu.init(n);
	edges.clear();
	forgo.clear();
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		valid[i] = false;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> cin_u >> cin_v >> cin_c;
		edges.push_back({cin_u, cin_v, cin_c});
	}
	sort(edges.begin(), edges.end(), [](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	for (auto e : edges) {
		if (dsu.join(e.u, e.v)) {
			adj[e.u].push_back({e.v, e.c});
			adj[e.v].push_back({e.u, e.c});
		}
		else {
			forgo.push_back(e);
			valid[e.u] = valid[e.v] = 1;
		}
	}
	dfs(1);
	init();
	for (auto e : forgo) {
		adj[e.u].push_back({e.v, e.c});
		adj[e.v].push_back({e.u, e.c});
	}
	for (int i = 1; i <= n; ++i) {
		if (!valid[i]) continue;
		val[++stt] = i;
		num[i] = stt;
		dijkstra(stt);
	}
	while (q --) {
		cin >> cin_u >> cin_v;
		res = LCA(cin_u, cin_v);
		for (auto e : forgo) res = min(res, min(LCA(cin_u, e.u) + LCA(e.v, cin_v), LCA(cin_u, e.v) + LCA(e.u, cin_v)) + d[num[e.u]][e.v]);
		cout << res << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; ++i) sol();
}