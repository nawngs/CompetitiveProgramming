#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 18;

int n, q, a[N + 3], par[N + 3][LG + 3], up[N + 3][LG + 3], mx[N + 3][LG + 3], cnt[N + 3], h[N + 3], f[N + 3];

vector < int > adj[N + 3];

int dfs(int u, int e) {
	cnt[u] = 1;
	h[u] = h[e] + 1;
	par[u][0] = e; mx[u][0] = a[e];
	for (int i = 1; i <= LG; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
	}
	int &pos = up[u][0]; pos = u; f[u] = u;
	for (int i = LG; i >= 0; i--) {
		if (mx[pos][i] <= a[u]) pos = par[pos][i];
		if (mx[f[u]][i] < a[u]) f[u] = par[f[u]][i];
	}
	pos = par[pos][0]; f[u] = par[f[u]][0];
	for (int i = 1; i <= LG; i++) up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto v : adj[u]) if (v != e) cnt[u] += dfs(v, u);
	return cnt[u];
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	if (u == v) return u;
	for (int j = LG; j >= 0; j--) {
		if (par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int getl(int u, int v) {
	int res = 1;
	for (int i = LG; i >= 0; i--) {
		if (h[up[u][i]] >= h[v]) {
			res += (1 << i);
			u = up[u][i];
		}
	}
	
	return res;
}

int getmx(int u, int v) {
	int res = a[u];
	for (int i = LG; i >= 0; i--) {
		// cout << par[u][i] << " " << v << " " << mx[u][i] << '\n';
		if (h[par[u][i]] >= h[v]) {
			res = max(res, mx[u][i]);
			u = par[u][i];
		}
	}
	return res;
}

int in[N + 3], timer = 0, chead[N + 3], cid[N + 3], nchain = 0, id[N + 3];

void hld(int u) {
	in[u] = ++ timer;
	id[timer] = u;
	cid[u] = nchain;
	if (!chead[nchain]) chead[cid[u]] = u;
	int maxv = -1;
	for (auto v : adj[u]) if (v != par[u][0] && (maxv == -1 || cnt[v] > cnt[maxv])) maxv = v;
	if (maxv != -1) hld(maxv);
	for (auto v : adj[u]) if (v != par[u][0] && v != maxv) {
		nchain ++;
		hld(v);
	}
}

using vi = vector < int >;

vi it[4 * N + 3];

vi merge(const vi &x, const vi &y) {
	vi res;
	int lx = 0, ly = 0;
	while (lx < SZE(x) || ly < SZE(y)) {
		if (lx == SZE(x)) {
			res.pb(y[ly++]);
			continue;
		}
		if (ly == SZE(y)) {
			res.pb(x[lx++]);
			continue;
		}
		if (x[lx] < y[ly]) res.pb(x[lx++]);
		else res.pb(y[ly++]);
	}
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].pb(h[f[id[l]]]);
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v, int val) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return lower_bound(it[node].begin(), it[node].end(), val) - it[node].begin();
	return query(lnode, u, v, val) + query(rnode, u, v, val);
}

int getr(int u, int ance, int mx) {
	int v = u;
	for (int i = LG; i >= 0; i--) 
		if (h[par[u][i]] >= h[ance] && getmx(par[u][i], ance) > mx) u = par[u][i];
	if (u == v && a[u] <= mx) return 0;
	int idx = cid[v];
	int res = 0;
	while (1) {
		if (idx == cid[u]) {
			res += query(1, 1, n, in[u], in[v], h[ance]);
			return res;
		}
		res += query(1, 1, n, in[chead[idx]], in[v], h[ance]);
		v = par[chead[idx]][0]; idx = cid[v];
	}
	return 0;	
}


int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0); 
	hld(1);
	build(1, 1, n);
	int lst = 0;
	while (q--) {
		int u, v; cin >> u >> v;
		// u = (u + lst) % n + 1;
		// v = (v + lst) % n + 1;
		int ance = LCA(u, v);
		lst = getl(u, ance) + getr(v, ance, getmx(u, ance));
		// cout << getmx(u, ance) << '\n';
		// cout << getl(u, ance) << " " << getr(v, ance, getmx(u, ance)) << '\n';
		cout << lst << '\n';
	}
}