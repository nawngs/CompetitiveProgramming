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

int n, in[500003], timer = 0, res[500003], out[500003];

vector < int > adj1[500003], adj2[500003];

void dfs(int u, int e) {
	in[u] = ++ timer;
	for (auto v : adj1[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
	out[u] = timer;
}

int it[4000003], lazy[4000003];

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
		return update(node, l, r);
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val); update(node * 2 + 1, mid + 1, r, u, v, val);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void dfs_get_res(int u, int e) {
	update(1, 1, n, in[u], out[u], 1);
	res[u] = query(1, 1, n, in[u], in[u]);
	for (auto v : adj2[u]) {
		if (v == e) continue;
		dfs_get_res(v, u);
	}
	update(1, 1, n, in[u], out[u], -1);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj1[u].pb(v); adj1[v].pb(u);
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj2[u].pb(v); adj2[v].pb(u);
	}
	dfs(1, 0);
	dfs_get_res(1, 0);
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}