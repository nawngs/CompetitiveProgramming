#include <bits/stdc++.h>

#define name ""
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
const ll SZE = 350;

struct Query {
	int l, r, id;
} Q[100003];

int n, m, q, h[100003], par[100003][17], ance[100003][17], cnt_child[100003], total = 0, c[100003], res[100003];

vector < int > adj[100003];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	cnt_child[u] = 1;
	for (int j = 1; j <= n; j++)
		par[u][j] = par[par[u][j - 1]][j - 1];
	for (auto v : adj[u]) {
		if (v == e) continue;
		par[v][0] = u; dfs(v, u);
		cnt_child[u] += cnt_child[v];
	}
}

int LCA(int u, int v) {
	if (u == 0 || v == 0) return 0;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 16; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	if (u == v) return u;
	for (int j = 16; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int chain_head[100003], chain_id[100003], nchain = 0, timer = 0, pos_it[100003];

void hld(int u = 1) {
	if (!chain_head[nchain]) chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos_it[u] = ++ timer;
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

int it[600003], lazy[600003], it2[600003];

#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node] * (r - l + 1);
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

int query(int u, int v) {
	int id_u = chain_id[u];
	int id_v = chain_id[v];
	int res = 0;
	while (1) {
		if (id_u == id_v) {
			res += query(1, 1, n, pos_it[v], pos_it[u]);
			return res;
		}
		res += query(1, 1, n, pos_it[chain_head[id_u]], pos_it[u]);
		u = par[chain_head[id_u]][0];
		id_u = chain_id[u];
	}
}

void update_hld(int u, int v, int val) {
	int id_u = chain_id[u];
	int id_v = chain_id[v];
	while (1) {
		if (id_u == id_v) {
			update(1, 1, n, pos_it[v], pos_it[u], val);
			return ;
		}
		update(1, 1, n, pos_it[chain_head[id_u]], pos_it[u], val);
		u = par[chain_head[id_u]][0];
		id_u = chain_id[u];
	}
}

void add(int id) {
	int u = c[id], ans = u;
	for (int j = 16; j >= 0; j--) {
		if (par[ans][j] == 0) continue;
		if (query(ans, par[ans][j]) == 0) {
			ans = par[ans][j];
		}
	}
	if (query(1, 1, n, pos_it[u], pos_it[u]) == 0) total += h[u] - h[ans] + 1;
	update_hld(u, 1, 1);
}

void sub(int id) {
	int u = c[id], ans = u;
	update_hld(u, 1, -1);
	if (query(1, 1, n, pos_it[u], pos_it[u]) != 0) return ;
	for (int j = 16; j >= 0; j--) {
		if (par[ans][j] == 0) continue;
		if (query(ans, par[ans][j]) == 0) ans = par[ans][j];
	}
	total -= (h[u] - h[ans] + 1);
}

int get(int l, int r) {
	int k = log2(r - l + 1);
	return LCA(ance[l][k], ance[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i]; ance[i][0] = c[i];
	}
	dfs(1, 0); hld();
	for (int j = 1; j <= 16; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			ance[i][j] = LCA(ance[i][j - 1], ance[i + (1 << (j - 1))][j - 1]);
		}
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].l >> Q[i].r;
		Q[i].id = i;
	}
	sort(Q + 1, Q + q + 1, [&](Query &x, Query &y) {
		if (x.l / SZE == y.l / SZE) return x.r < y.r;
		return x.l < y.l;
	});
	int l = Q[1].l, r = Q[1].r;
	for (int i = l; i <= r; i++) 
		add(i);
	res[Q[1].id] = total - h[get(l, r)] + 1;
	for (int i = 2; i <= q; i++) {
		while (r < Q[i].r) add(++r);
		while (r > Q[i].r) sub(r--);	
		while (l > Q[i].l) add(--l);
		while (l < Q[i].l) sub(l++);
		res[Q[i].id] = total - h[get(l, r)] + 1;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}