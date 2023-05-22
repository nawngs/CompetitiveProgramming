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

const string NAME = "SparseGraph";
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
	ll c;
	Edge(int _u, int _v, ll _c) : u(_u), v(_v), c(_c) {};
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

ll h[100002], par[100002][19], s[100002][19], res = 0, d[45][45], list_val[45], val_index[100002];

int n, m, log2_n, cnt_list = 0;

vector < Edge > edges;

vector < pll > adj[100002], adj2[45];

void dfs1(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == par[u][0]) continue;
		par[v.fi][0] = u;
		s[v.fi][0] = v.se;
		dfs1(v.fi); 
	}
}

void init() {
	for (int j = 1; j <= log2_n; j++) 
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] != 0) s[i][j] = s[i][j - 1] + s[par[i][j - 1]][j - 1];
		}
}

ll lca(ll u, ll v) {
	if (h[u] > h[v]) swap(u, v);
	ll ans = 0;
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				ans += s[v][j];
				v = par[v][j];
			}
		}
	}
	if (v == u) return ans;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[u][j] != par[v][j]) {
			ans += s[u][j] + s[v][j];
			u = par[u][j];
			v = par[v][j];
		}
	}
	return ans + s[u][0] + s[v][0];
}

void dijkstra(int start) {
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= cnt_list; i++) d[start][i] = INF;
	d[start][start] = 0;
	heap.push({d[start][start], start});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (d[start][u.se] != u.fi) continue;
		for (auto v : adj2[u.se]) {
			ll tam = v.se + u.fi;
			if (tam < d[start][v.fi]) {
				d[start][v.fi] = tam;
				heap.push({tam, v.fi});
			}
		}
	} 
}

void sol() {
	cin >> n >> m;
	memset(val_index, 255, sizeof(val_index));
	log2_n = log2(n) + 1;
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		edges.push_back({u, v, c});
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
			if (val_index[e.u] == -1) {
				cnt_list ++;
				val_index[e.u] = cnt_list;
				list_val[cnt_list] = e.u;
			}
			if (val_index[e.v] == -1) {
				cnt_list ++;
				val_index[e.v] = cnt_list;
				list_val[cnt_list] = e.v;
			}
			adj2[val_index[e.u]].push_back({val_index[e.v], e.c});
			adj2[val_index[e.v]].push_back({val_index[e.u], e.c});
		}
	}
	dfs1(1);	
	init();
	for (int i = 1; i <= cnt_list; i++) dijkstra(i);
	int q;
	cin >> q;
	while (q --) {
		ll u, v;
		cin >> u >> v;
		ll ans = lca(u, v);
		for (int i = 1; i <= cnt_list; i++) 
			for (int j = 1; j <= cnt_list; j++) ans = min(ans, lca(u, list_val[i]) + lca(list_val[j], v) + d[i][j]);
		cout << ans << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
