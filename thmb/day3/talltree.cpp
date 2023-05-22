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

const string NAME = "talltree";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, num[500003], tail[500003], timeDFS = 0, h[500003];

vector < int > a;

vector < int > adj[500003];

pll it[4000003], lazy[4000003];

void dfs(int u) {
	a.push_back(u);
	num[u] = tail[u] = ++ timeDFS;
	for (auto v : adj[u]) {
		if (num[v] != 0) continue;
		h[v] = h[u] + 1;
		dfs(v);
	}
	tail[u] = timeDFS;
}

pll merge(pll x, pll y) {
	pll res;
	res.fi = (x.fi + y.fi) % MOD;
	res.se = (x.se + y.se) % MOD;
	return res;
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node].fi = 0;
		it[node].se = h[a[l]];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update_node(int node, int l, int r) {
	if (lazy[node] != make_pair(0ll, 0ll)) {
		//cout << node << " " << l << " " << r << " " << a[l] << " " << lazy[node].fi << " " << lazy[node].se << " " << it[node].se << '\n';
		it[node].fi += lazy[node].fi * 1ll * (r - l + 1) - lazy[node].se * it[node].se;
		it[node].fi %= MOD;
		it[node].fi += MOD;	
		it[node].fi %= MOD;
		//cout << it[node].fi << '\n';
		if (l != r) {
			lazy[node * 2] = merge(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = merge(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = {0, 0};
	}
}

void update(int node, int l, int r, int u, int v, pll val) {
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
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].fi;
	int mid = (l + r) / 2;
	return (query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v)) % MOD;
}

main() {
	fast;
	//fre();
	int O;
	cin >> O;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	a.push_back(-1);
	dfs(1);
	//cout << 123 << '\n';
	build_tree(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s == "add") {
			ll v, k, l;
			cin >> v >> k >> l;
			k = ((k % MOD) + MOD) % MOD;
			l = ((l % MOD) + MOD) % MOD;
			//cout << k << " " << l << '\n';
			update(1, 1, n, num[v], tail[v], {(k + h[v] * l) % MOD, l});
		}
		if (s == "get") {
			int v;
			cin >> v;
			cout << query(1, 1, n, num[v], num[v]) << ' ';
		}
		if (s == "sum") {
			int v;
			cin >> v;
			cout << query(1, 1, n, num[v], tail[v]) << ' ';
		}
	}
}
