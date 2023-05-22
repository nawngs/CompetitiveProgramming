#include <bits/stdc++.h>

#define name ""
#define test "test"
#define int ll
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

int n, s, q, root, in[100003], out[100003], timer = 0, h[100003], par[100003][20];

bool shop[100003];

pii edges[100003];

ll dis[100003], f[100003], g[100003][20];

vector < pll > adj[100003]; 

void dfs(int u, int e, ll len) {
	in[u] = out[u] = ++ timer;
	dis[u] = len;
	f[u] = (shop[u] ? 0 : LINF);
	h[u] = h[e] + 1;
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		par[v.fi][0] = u;
		for (int i = 1; i <= 19; i++)
			par[v.fi][i] = par[par[v.fi][i - 1]][i - 1];
		dfs(v.fi, u, len + v.se);
		f[u] = min(f[u], f[v.fi] + v.se);
	}
	out[u] = timer;
}

void dfs2(int u, int e) {
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		g[v.fi][0] = f[u] - dis[u];
		for (int i = 1; i <= 19; i++) {
			g[v.fi][i] = min(g[v.fi][i - 1], g[par[v.fi][i - 1]][i - 1]);
		}
		dfs2(v.fi, u);
	}
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> q >> root;
	for (int i = 1; i < n; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, c}); adj[v].push_back({u, c});
		edges[i] = {u, v};
	}
	for (int i = 1; i <= s; i++) {
		int x; cin >> x;
		shop[x] = 1;
	}
	dfs(root, 0, 0);
	dfs2(root, 0);
	while (q--) {
		int id, node; cin >> id >> node;
		int u = edges[id].fi, v = edges[id].se;
		if (par[u][0] == v) swap(u, v);
		if (!(in[v] <= in[node] && in[node] <= out[v])) {
			cout << "escaped" << '\n';
			continue;
		}
		if (f[v] >= LINF) {
			cout << "oo" << '\n';
			continue;
		}
		ll res = f[node], d = h[node] - h[v], val = dis[node];
		for (int i = 19; i >= 0; i--) {
			if (d >> i & 1) {
				res = min(res, val + g[node][i]);
				node=  par[node][i];
			}
		}
		if (res > 1ll * n * INF) cout << "oo" << '\n';
		else cout << res << '\n';
	}
}