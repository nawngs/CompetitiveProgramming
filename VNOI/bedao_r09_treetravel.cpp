#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], p[100003], cnt_child[100003];

int chain_head[100003], chain_id[100003], pos_it[100003], nchain = 0, timer = 0, res[100003];

ll it[800003], lazy[800003];

vector < int > adj[100003];

void dfs(int u) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		dfs(v);
		cnt_child[u] += cnt_child[v];
	}
}

void hld(int u) {
	if (chain_head[nchain] == 0) chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos_it[u] = ++ timer;
	int max_v = -1;
	for (auto v : adj[u]) 
		if (max_v == -1 || cnt_child[max_v] < cnt_child[v]) max_v = v;
	if (max_v != -1) hld(max_v);
	for (auto v : adj[u]) {
		if (v == max_v) continue;
		nchain ++;
		hld(v);
	}
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = 1;
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update_node(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] = (it[node] + lazy[node] * (r - l + 1)) % MOD;
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
			lazy[node * 2] %= MOD;
			lazy[node * 2 + 1] %= MOD;
		}
		lazy[node] = 0;
	}
}

int query(int node, int l, int r, int pos) {
	update_node(node, l, r);
	if (pos < l || pos > r) return 0;
	if (pos == l && pos == r) return it[node];
	int mid = (l + r) / 2;
	return (query(node * 2, l, mid, pos) + query(node * 2 + 1, mid + 1, r, pos)) % MOD;
}

void update(int node, int l, int r, int u, int v, int val) {
	update_node(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

signed main() {
	fast;
	cin >> n;
	int root;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
		if (p[i] == 0) root = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(root);
	hld(root);	
	build_tree(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int val = query(1, 1, n, pos_it[a[i]]);
		res[a[i]] = val;
		if (p[a[i]] == 0) continue;
		int u = p[a[i]];
		int id = chain_id[u];
		while (1) {
			if (chain_head[id] == root) {
				update(1, 1, n, 1, pos_it[u], val);
				break;
			}
			update(1, 1, n, pos_it[chain_head[id]], pos_it[u], val);
			u = p[chain_head[id]];
			id = chain_id[u];
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}
