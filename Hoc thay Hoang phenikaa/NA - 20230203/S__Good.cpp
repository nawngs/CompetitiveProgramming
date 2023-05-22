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

int n, m, q, a[203], ans[203], par[203][20], h[203];

vector < int > adj[203];

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

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	while (q--) {
		char c; cin >> c;
		if (c == 't') {
			int l, r, u; cin >> l >> r >> u;
			for (int i = l; i <= r; i++) {
				ans[i] -= LCA(a[i], u);
				a[i] = u;
			}
		}
		if (c == 'e') {
			int u, x; cin >> u >> x;
			for (int i = 1; i <= m; i++)
				if (a[i] == u) ans[i] += x;
		}
		if (c == 'q') {
			int u; cin >> u;
			cout << ans[u] << '\n';
		}
	}
}