#include <bits/stdc++.h>

#define name "terminal"
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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 350;

int n, m, sz[N + 3], par[N + 3], deg[N + 3];

vector < int > adj[N + 3];

pii ed[2 * N + 3];

bool invalid[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u; sz[u] += sz[v];
}

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> ed[i].fi >> ed[i].se;
		deg[ed[i].fi] ++; deg[ed[i].se] ++;
		adj[ed[i].fi].pb(ed[i].se); adj[ed[i].se].pb(ed[i].fi);
	}
	ll res = 0;
	for (int t = 1; t <= BASE; t++) {
		for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
		for (int i = 1; i <= m; i++) 
			if (!invalid[ed[i].fi] && !invalid[ed[i].se]) join(ed[i].fi, ed[i].se);
		for (int i = 1; i <= n; i++) if (!invalid[i] && i == find(i)) res = max(res, 1ll * t * sz[i]);
		queue < int > q;
		for (int i = 1; i <= n; i++) if (deg[i] == t) q.push(i), invalid[i] = 1;
		while (q.size()) {
			auto u = q.front(); q.pop();
			for (auto v : adj[u]) {
				deg[v] --;
				if (deg[v] <= t && !invalid[v]) {
					invalid[v] = 1;
					q.push(v);
				}
			}
		}
	}
	cout << res;
}