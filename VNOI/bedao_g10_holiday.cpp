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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, q, cnt_child[1000003], par[1000003], ans[1000003];

vector < int > a;

vector < pll > adj[1000003];

map < int, ll > d[1000003];

bool used[1000003], in_test[1000003];

int dfs(int u, int e) {
	cnt_child[u] = 0;
	for (auto v : adj[u]) {
		if (v.fi == e || used[v.fi]) continue;
		cnt_child[u] += dfs(v.fi, u);
	}
	return cnt_child[u];
}

int get_centroid(int u, int e, int total) {
	for (auto v : adj[u]) {
		if (v.fi == e || used[v.fi]) continue;
		if (cnt_child[v.fi] > total / 2) return get_centroid(v.fi, u, total);
	}
	return u;
}

void dfs2(int u, int e, int root, ll cur) {
	d[root][u] = cur;
	for (auto v : adj[u]) {
		if (v.fi == e || used[v.fi]) continue;
		dfs2(v.fi, u, root, cur + v.se);
	}
}

void centroid(int n, int e) {
	int C = get_centroid(n, 0, dfs(n, 0));
	par[C] = e;
	used[C] = 1;
	dfs2(C, 0, C, 0);
	for (auto v : adj[C]) 
		if (!used[v.fi]) centroid(v.fi, C);
}

void add(int u) {
	in_test[u] = 1;
	for (int v = u; v != 0; v = par[v]) ans[v] = max(ans[v], d[v][u]);
}

void erase(int u) {
	in_test[u] = 0;
	for (int v = u; v != 0; v = par[v]) ans[v] = -LINF;
}

ll query(int u) {
	ll res = -LINF;
	for (int v = u; v != 0; v = par[v]) {
		if (!in_test[v]) res = max(res, ans[v] + d[v][u]);
		else res = max(res, d[v][u]);
	}
	return res;
}

int main() {
	fast;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		c += 1;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	centroid(1, 0);
	while (q--) {
		int k; cin >> k;
		a.resize(k);
		ll res = -LINF;
		for (auto &x : a) 
			cin >> x;
		
		for (auto x : a) {
			cout << x << " " << query(x) << '\n';
			res = max(res, query(x));
			add(x);
		}
		for (auto x : a) 
			erase(x);

		cout << res << '\n';
	}
}
