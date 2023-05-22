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

const string NAME = "milkvisits";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int u, v, val;
} querys[nmax + 3];

int n, q, e[nmax + 3], cnt_child[nmax + 3], par[nmax + 3][20], log2_n, h[nmax + 3], res[nmax + 3], timeDFS = 0;

int chain_head[nmax + 3], chain_id[nmax + 3], pos_it[nmax + 3], nchain = 0, id_it = 0;

int it[4 * nmax + 3];

vector < int > adj[nmax + 3];

void dfs(int u = 1) {
	cnt_child[u] = 1;
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
		cnt_child[u] += cnt_child[v];
	}
}

void hld(int u = 1) {
	if (chain_head[nchain] == -1) chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos_it[u] = ++id_it;
	int max_v = -1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		if (max_v == -1 || cnt_child[v] > cnt_child[max_v]) max_v = v;
	}
	if (max_v != -1) hld(max_v);
	for (auto v : adj[u]) {
		if (v == par[u][0] || v == max_v) continue;
		nchain ++;
		hld(v);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) par[i][j] = 0;

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			//cout << i << " " << j << " " << par[i][j] << '\n';
		}
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int query_tree(int u, int a) {
	int res = 0;
	int uid = chain_id[u];
	int aid = chain_id[a];
	while (1) {	
		if (aid == uid) {
			res = max(res, query(1, 1, n, pos_it[a], pos_it[u]));
			break;
		}
		res = max(res, query(1, 1, n, pos_it[chain_head[uid]], pos_it[u]));
		u = par[chain_head[uid]][0];
		uid = chain_id[u];
	}
	return res;
}

int main() {
	fast;
	fre();
	cin >> n >> q;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= n; i++) cin >> e[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	memset(chain_head, 255, sizeof(chain_head));
	hld();
	init();
	vector < pii > tmp;
	for (int i = 1; i <= n; i++) tmp.push_back({e[i], i});
	for (int i = 1; i <= q; i++) {
		cin >> querys[i].u >> querys[i].v >> querys[i].val;
		tmp.push_back({querys[i].val, n + i});
	}
	sort(tmp.begin(), tmp.end(), [&](pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	for (auto x : tmp) {
		if (x.se <= n) update(1, 1, n, pos_it[x.se], x.fi);
		else {
			int i = x.se - n;
			int u = querys[i].u;
			int v = querys[i].v;
			int a = LCA(u, v);
			int ans = max(query_tree(u, a), query_tree(v, a));
			res[i] = (ans == x.fi);
		}
	}
	for (int i = 1; i <= q; i++) cout << res[i];
}
