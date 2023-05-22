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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e4;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Node {
	int min_, max_;
} it[8 * nmax + 3];

int n, h[nmax + 3], par[nmax + 3][20], cnt_child[nmax + 3], chain_head[nmax + 3], chain_id[nmax + 3], nchain, timer;

int lazy[8 * nmax + 3];

int pos_it[nmax + 3], log2_n;

vector < int > adj[nmax + 3];

pair < pii, int > edges[nmax + 3];

string s;

void dfs_pre(int u = 1) {
	cnt_child[u] = 1;
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs_pre(v);
		cnt_child[u] += cnt_child[v];
	}
}

void hld(int u = 1) {
	if (chain_head[nchain] == -1) chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos_it[u] = ++timer;
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
		}
	}
}

pii LCA(int u, int v) {
	bool th = false;
	if (h[u] > h[v]) {
		swap(u, v);
		th = 1;
	}
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[par[v][j]] > h[u]) {
				v = par[v][j];
			}
		}
		if (u == par[v][0]) return {v, v};
		v = par[v][0];
	}
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	if (th) swap(u, v);
	return {u, v};
}

Node merge(Node const &x, Node const &y) {
	Node res;
	res.min_ = min(x.min_, y.min_);
	res.max_ = max(x.max_, y.max_);
	return res;
}

void update_node(int node, int l, int r) {
	if (lazy[node] != 1) {
		it[node].min_ *= -1;
		it[node].max_ *= -1;
		swap(it[node].min_, it[node].max_);
		if (l != r) {
			lazy[node * 2] *= lazy[node];
			lazy[node * 2 + 1] *= lazy[node];
		}
		lazy[node] = 1;
	}
}

void update(int node, int l, int r, int pos, int val) {
	update_node(node, l, r);
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].min_ = it[node].max_ = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, int val) {
	update_node(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] *= val;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) {
		Node res;
		res.min_ = INF;
		res.max_ = -INF;
		return res;
	}
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return merge(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void update_(int u, int v) {
	int id_u = chain_id[u];
	int id_v = chain_id[v];
	//cout << u << " " << v << " " << pos_it[u] << " " << pos_it[v] << '\n';
	while (1) {
		if (id_u == id_v) {
			update(1, 1, n, pos_it[v], pos_it[u], -1);
			return ;
		}
		update(1, 1, n, pos_it[chain_head[id_u]], pos_it[u], -1);
		u = par[chain_head[id_u]][0];
		id_u = chain_id[u];
	}
}

int query_(int u, int v) {
	int res = -INF;
	int id_u = chain_id[u];
	int id_v = chain_id[v];
	while (1) {
		if (id_u == id_v) {
			res = max(res, query(1, 1, n, pos_it[v], pos_it[u]).max_);
			return res;
		}
		res = max(res, query(1, 1, n, pos_it[chain_head[id_u]], pos_it[u]).max_);
		u = par[chain_head[id_u]][0];
		id_u = chain_id[u];
	}
}

void sol() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i] = {{u, v}, c};
	}
	dfs_pre();
	memset(chain_head, 255, sizeof(chain_head));
	timer = 0;
	nchain = 0;
	hld();
	init();
	for (int i = 1; i < n; i++) {
		if (par[edges[i].fi.fi][0] == edges[i].fi.se) swap(edges[i].fi.fi, edges[i].fi.se);
		update(1, 1, n, pos_it[edges[i].fi.se], edges[i].se);
	}
	while (cin >> s && s != "DONE") {
		if (s == "CHANGE") {
			int i, val;
			cin >> i >> val;
			update(1, 1, n, pos_it[edges[i].fi.se], val);
		}
		if (s == "NEGATE") {
			int u, v;
			cin >> u >> v;
			if (u == v) continue;
			pii temp = LCA(u, v);
			if (temp.fi == temp.se) {
				if (par[temp.fi][0] == u) update_(v, temp.fi);
				else update_(u, temp.fi);
			}
			else {
				update_(u, temp.fi);
				update_(v, temp.se);
			}
		}
		if (s == "QUERY") {
			int u, v;
			cin >> u >> v;
			if (u == v) {
				cout << 0 << '\n';
				continue;
			}
			pii temp = LCA(u, v);
			if (temp.fi == temp.se) {
				if (par[temp.fi][0] == u) cout << query_(v, temp.fi);
				else cout << query_(u, temp.fi);
			}
			else cout << max(query_(u, temp.fi), query_(v, temp.se));
			cout << '\n';
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
