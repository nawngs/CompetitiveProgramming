#include <bits/stdc++.h>

#define int ll
#define name "test"
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

struct Data {
	int l, r, cur;
	ll val;
	Data (int _l, int _r, int _cur, ll _val) {
		l = _l, r = _r, cur = _cur, val = _val;
	}
};

struct Compare {
	bool operator() (Data x, Data y) const {
		return x.l < y.l;
	}
};

set < Data, Compare > ms;

int n, m, q, par[200003][20], h[200003];

vector < int > adj[200003];

ll t[200003];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (int i = 1; i <= 19; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == e) continue;
		par[v][0] = u; dfs(v, u);
	}
}

int LCA(int u, int v) {
	int res = 0;
	if (h[u] > h[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) 
		if (h[par[v][i]] >= h[u]) {
			res += (1 << i);
			v = par[v][i];
		}
	if (u == v) return res;
	for (int i = 19; i >= 0; i--) 
		if (par[u][i] != par[v][i]) {
			res += (1 << (i + 1));
			u = par[u][i]; v = par[v][i];
		}
	res += 2;
	return res;
}

ll it[1600003], lazy[1600003];

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

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val); update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0ll;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

signed main() {
	fast;
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		ms.insert(Data(i, i, x, t[x]));
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	while (q--) {
		char c; cin >> c;
		if (c == 'e') {
			int u; ll x; cin >> u >> x;
			t[u] += x;
		}
		if (c == 't') {
			int l, r, u; cin >> l >> r >> u;
			auto itl = ms.lower_bound(Data(l + 1, 0, 0, 0)); itl --;
			auto itr = ms.lower_bound(Data(r + 1, 0, 0, 0)); itr --;
			Data reml(-1, -1, -1, -1), remr(-1, -1, -1, -1);
			if (itl->l < l) reml = Data(itl->l, l - 1, itl->cur, itl->val);
			if (itr->r > r) remr = Data(r + 1, itr->r, itr->cur, itr->val);
			auto it = itl;
			itr++;
			while (it != itr) {
				update(1, 1, m, max(it->l, l), min(it->r, r), t[it->cur] - it->val);
				update(1, 1, m, max(it->l, l), min(it->r, r), -LCA(it->cur, u));
				it ++;
			}
			ms.erase(itl, itr);	
			if (reml.l != -1) ms.insert(reml);
			if (remr.l != -1) ms.insert(remr);
			ms.insert(Data(l, r, u, t[u]));
		}
		if (c == 'q') {
			int u; cin >> u;
			auto it = ms.lower_bound(Data(u + 1, 0, 0, 0)); it --;
			cout << query(1, 1, m, u, u) + t[it->cur] - it->val << '\n';
		}
		//  for (auto x : ms) cout << x.l << " " << x.r << " " << x.cur << " " << x.val << '\n';
		// for (int i = 1; i <= n; i++) cout << i << " " << query(1, 1, m, i, i) << '\n';
		// cout << "//##############################################################################" << '\n';
	}
}
