#include <bits/stdc++.h>

#define name "FIREWORK"
#define test "test"
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
	int t, u, s, id;
	ll c;
	bool IsQuery;
} a[200003];

int n, m, q;

ll res[100003], it[400003], lazy[400003], par[100003], f[100003], g[100003], h[100003];

ll s[100003];

vector < int > adj[100003];

void dfs(int u, int e, int dis, int maxdis, ll val) {
	s[u] += val;
	if (dis == maxdis) return;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u, dis + 1, maxdis, val);
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

void update(int node, int l, int r, int u, int v, ll val) {
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
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void dfs(int u, int e) {
	par[u] = e;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	bool th = 1;
	for (int i = 1; i < n; i++) {
		 int u, v; cin >> u >> v;
		 if (u != i || v != i + 1) th = false;
		 adj[u].push_back(v); adj[v].push_back(u);
	}
	bool sub5 = 1;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].t >> a[i].u >> a[i].c >> a[i].s;
		if (a[i].s != 2) sub5 = false;
		a[i].IsQuery = false;
	}
	for (int i = 1; i <= q; i++) {
		cin >> a[i + m].t >> a[i + m].u;
		a[i + m].IsQuery = true;
		a[i + m].id = i;
	}
	sort(a + 1, a + m + q + 1, [&](Data &x, Data &y) {
		if (x.t != y.t) return x.t < y.t;
		return (!x.IsQuery);
	});
	if (sub5) {
		dfs(1, 0);
		for (int i = 1; i <= m + q; i++) {
			if (!a[i].IsQuery) {
				f[a[i].u] += a[i].c;
				g[a[i].u] += a[i].c;
				f[par[a[i].u]] += a[i].c;
				h[par[par[a[i].u]]] += a[i].c;
			}
			else res[a[i].id] = h[a[i].u] + f[par[a[i].u]] + f[a[i].u] - g[a[i].u];
		}
		for (int i = 1; i <= q; i++) cout << res[i] << '\n';
		return 0;
	}
	if (!th) {
		for (int i = 1; i <= m + q; i++) {
			if (!a[i].IsQuery) 
				dfs(a[i].u, 0, 0, a[i].s, a[i].c);
			else res[a[i].id] = s[a[i].u];
		}
		for (int i = 1; i <= q; i++) cout << res[i] << '\n';
	}
	else {
		for (int i = 1; i <= m + q; i++) {
			if (!a[i].IsQuery) 
				update(1, 1, n, max(1, a[i].u - a[i].s), min(n, a[i].u + a[i].s), a[i].c);
			else res[a[i].id] = query(1, 1, n, a[i].u, a[i].u);
		}
		for (int i = 1; i <= q; i++) cout << res[i] << '\n';
	}
}