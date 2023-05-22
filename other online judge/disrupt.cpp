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

const string NAME = "disrupt";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 50003;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	 int u, v, val;
} tmp[2 * nmax + 3];

int n, q, par[nmax + 3], cnt_child[nmax + 3], edge_id[nmax + 3], res[nmax + 3], uu, vv, cc;

int chain_head[nmax + 3], nchain = 0, pos_it[nmax + 3], id_it = 0, tail[nmax + 3], val_at_pos[nmax + 3];

pii edges[nmax + 3];

int it[4 * nmax + 5];

vector < int > adj[nmax + 3];

void dfs(int u = 1) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
		cnt_child[u] += cnt_child[v];
	}
}

void hld(int u = 1) {
	if (chain_head[nchain] == -1) chain_head[nchain] = u;
	pos_it[u] = ++ id_it;
	val_at_pos[id_it] = u;
	int maxv = -1;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		if (maxv == -1 || cnt_child[v] > cnt_child[maxv]) maxv = v;
	}
	if (maxv != -1) hld(maxv);
	for (auto v : adj[u]) {
		if (v == par[u] || v == maxv) continue;
		nchain ++;
		hld(v);
	}
	tail[u] = val_at_pos[id_it];
}

void build_tree(int node, int l, int r) {
	it[node] = INF;
	if (l == r) return ;
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] = min(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
} 

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void minimize(int &x, int y) {
	x = min(x, y);
	return ;
}

int main() {
	fre();
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> uu >> vv;
		adj[uu].push_back(vv);
		adj[vv].push_back(uu);
		edges[i] = {uu, vv};
		res[i] = INF;
	}
	dfs();
	memset(chain_head, 255, sizeof(chain_head));
	hld();
	for (int i = 2; i <= n; i++) {
		tmp[i].u = i;
		tmp[i].v = tail[i];
		tmp[i].val = -1;
	}
	for (int i = 1; i < n; i++) {
		if (par[edges[i].se] == edges[i].fi) edge_id[edges[i].se] = i;
		else edge_id[edges[i].fi] = i;
	}
	for (int i = 1; i <= q; i++) {
		cin >> uu >> vv >> cc;
		if (pos_it[vv] < pos_it[uu]) swap(uu, vv);
		tmp[i + n].u = uu;
		tmp[i + n].v = vv;
		tmp[i + n].val = cc;
	}
	build_tree(1, 1, n);
	sort(tmp + 1, tmp + n + q + 1, [&](Data &x, Data &y) {
		return (pos_it[x.u] < pos_it[y.u]) || (x.u == y.u && (x.val == -1));
	});
	for (int i = 1; i <= n + q; i++) {
		auto x = tmp[i];
		int u = x.u, v = x.v, c = x.val;
		if (c != -1) update(1, 1, n, pos_it[v], c);
		else minimize(res[edge_id[u]], query(1, 1, n, pos_it[u], pos_it[v]));
	}
	build_tree(1, 1, n);
	sort(tmp + 1, tmp + n + q + 1, [&](Data &x, Data &y) {
		return (pos_it[x.v] > pos_it[y.v]) || (x.v == y.v && (x.val == -1));
	});
	for (int i = 1; i <= n + q; i++) {
		auto x = tmp[i];
		int u = x.u, v = x.v, c = x.val;
		if (c != -1) update(1, 1, n, pos_it[u], c);
		else minimize(res[edge_id[u]], query(1, 1, n, pos_it[u], pos_it[v]));
	}
	for (int i = 1; i < n; i++) cout << (res[i] == INF ? -1 : res[i]) << '\n';
}
