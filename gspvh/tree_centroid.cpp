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

const string NAME = "tree";
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

int n, sze[200003];

vector < pair < int, ll > > adj[200003];

bool used[200003];

int dfs_get_size(int u, int e) {
	sze[u] = 1;
	for (auto v : adj[u]) {
		if (used[v.fi] || v.fi == e) continue;
		sze[u] += dfs_get_size(v.fi, u);
	}
	return sze[u];
}

// hld

int chain_head[200003], chain_id[200003], lazy[1200003], pos_it[1200003], val[200003], nchain = 0, timer = 0, p[200003];

int it[1200003];

void hld(int u, int e) {
	if (!chain_head[nchain]) 
		chain_head[nchain] = u;
	chain_id[u] = nchain;
	pos_it[u] = ++ timer;
	val[timer] = u;
	int max_v = -1;
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		p[v.fi] = u;
		if (v.fi == -1 || sze[v.fi] > sze[max_v]) 
			max_v = v.fi;
	}
	if (max_v != -1) hld(max_v, u);
	for (auto v : adj[u]) {
		if (v.fi == e || v.fi == max_v) continue;
		nchain ++; hld(v.fi, u);
	}
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
		lazy[node] ++;
		update(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void update(int u) {
	int id = chain_id[u];
	while (1) {
		if (id == chain_id[1]) {
			update(1, 1, n, 1, pos_it[u]);
			return ;
		}
		update(1, 1, n, pos_it[chain_head[id]], pos_it[u]);
		u = p[chain_head[id]];
		id = chain_id[u];
	}
}

int walk(int node, int l, int r, int k) {
	if (l == r) return val[l];
	int mid = (l + r) / 2;
	update(node * 2, l, mid); update(node * 2 + 1, mid + 1, r);
	if (it[node * 2 + 1] * 2 > k) return walk(node * 2 + 1, mid + 1, r, k);
	return walk(node * 2, l, mid, k);
}

// centroid

int par[200003];

ll f[200003], dis[200003][18];

pair < int, ll > dp[200003];

map < int, ll > d[200003];

int get_centroid(int u, int ms, int e) {
	for (auto v : adj[u]) {
		if (used[v.fi] || v.fi == e) continue;
		if (sze[v.fi] * 2 > ms) return get_centroid(v.fi, ms, u);
	}
	return u;
}

void dfs2(int u, int e, int pos, ll len) {
	d[pos][u] = len;
	for (auto v : adj[u]) {
		if (used[v.fi] || v.fi == e) continue;
		dfs2(v.fi, u, pos, len + v.se);
	}
}

void centroid(int u, int e) {
	int C = get_centroid(u, dfs_get_size(u, 0), 0);
	par[C] = e;
	dfs2(C, 0, C, 0);
	used[C] = 1;
	for (auto v : adj[C]) {
		if (used[v.fi] || v.fi == e) continue;
		centroid(v.fi, C);
	}
}

void add(int u) {
	int pre = -1, cnt = 0;
	for (int v = u; v != 0; v = par[v]) {
		dp[v].fi ++;
		dp[v].se += dis[u][cnt];
		if (pre != -1) f[pre] += dis[u][cnt];
		cnt ++;
		pre = v;
	}
}

ll query(int u) {
	ll res = 0;
	int pre = -1, cnt = 0;
	for (int v = u; v != 0; v = par[v]) {
		pll tam = dp[v];
		if (pre != -1) {
			tam.fi -= dp[pre].fi;
			tam.se = tam.se - f[pre];
		}
		//if (u == 5 && v == 3) cout << tam.fi << " " << tam.se << '\n';
		res += tam.se + tam.fi * dis[u][cnt];
		cnt ++;
		pre = v;
	}
	return res;
}

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c}); adj[v].push_back({u, c});
	}
	dfs_get_size(1, 0);
	hld(1, 0);
	centroid(1, 0);
	for (int u = 1; u <= n; u++) {
		int cnt = 0;
		for (int v = u; v != 0; v = par[v]) {
			dis[u][cnt] = d[v][u];
			cnt ++;
		}
	}
	for (int i = 1; i <= n; i++) {
		update(i);
		add(i);
		int pos = walk(1, 1, n, i);
		//query(pos);
		cout << query(pos) << ' ';
	}
}
