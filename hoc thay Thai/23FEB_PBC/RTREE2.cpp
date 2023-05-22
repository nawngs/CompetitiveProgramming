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

int n, q, sz[100003], par[100003][21], h[100003];

int chain_head[100003], nchain = 0, chain_id[100003], timer = 0, pos[100003];

pii edges[100003];

vector < int > adj[100003];

int it[800003], lazy[800003];

void dfs(int u, int e) {
	sz[u] = 1;
	for (int i = 1; i <= 18; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == e) continue;
		h[v] = h[u] + 1;
		par[v][0] = u;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

void hld(int u) {
	if (chain_head[nchain] == -1) 
		chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos[u] = ++ timer;
	int maxv = -1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		if (maxv == -1 || sz[maxv] < sz[v]) maxv = v;
	}
	if (maxv != -1) hld(maxv);
	for (auto v : adj[u]) {
		if (v == par[u][0] || v == maxv) continue;
		nchain ++; hld(v);
	}
}

pii LCA(int u, int v) {
	bool th = 0;
	if (h[u] > h[v]) {
		swap(u, v), th = 1;
	}
	if (h[u] != h[v]) {
		for (int j = 18; j >= 0; j--) 
			if (h[par[v][j]] > h[u]) 
				v = par[v][j];
		if (u == par[v][0]) return {v, v};
		v = par[v][0];
	}
	for (int j = 18; j >= 0; j--) 
		if (par[u][j] != 0 && par[u][j] != par[v][j]) 
			u = par[u][j], v = par[v][j];
	if (th) swap(u, v);
	return mp(u, v);
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = 1;
		return update(node, l, r);
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v); update(node * 2 + 1, mid + 1, r, u, v);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(int u, int v) {
	int id_u = chain_id[u], id_v = chain_id[v];
	while (1) {
		if (id_u == id_v) return update(1, 1, n, pos[v], pos[u]);
		update(1, 1, n, pos[chain_head[id_u]], pos[u]);
		u = par[chain_head[id_u]][0];
		id_u = chain_id[u];
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
		edges[i] = mp(u, v);
	}
	dfs(1, 0);
	memset(chain_head, 255, sizeof(chain_head));
	hld(1);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int u, v; cin >> u >> v;
			pii temp = LCA(u, v);
			if (temp.fi == temp.se) {
				if (u == par[temp.fi][0]) update(v, temp.fi);
				if (v == par[temp.fi][0]) update(u, temp.fi);
			}
			else update(u, temp.fi), update(v, temp.se);
		}
		else {
			int id; cin >> id;
			int u = edges[id].fi, v = edges[id].se;
			if (par[v][0] == u) swap(u, v);
			cout << query(1, 1, n, pos[u], pos[u]) << '\n';
		}
	}
}