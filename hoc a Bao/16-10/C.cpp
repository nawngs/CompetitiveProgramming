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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, par[NMAX + 3], dsu[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	for (auto v : adj[u]) if (v != par[u]) {
		par[v] = u;
		dfs(v);
	}
}

int find(int u) {
	return (dsu[u] < 0 ? u : dsu[u] = find(dsu[u]));
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return ;
	dsu[u] += dsu[v]; dsu[v] = u;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		par[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1);
	// for (int msk = 1; msk <= n; msk++) 
		// for (int i = msk; i > 0; i = msk & (i - 1)) {
			// assert((msk & i) == i);
			// p[i].pb(msk);
		// }
	ll res = n;
	for (int i = 1; i <= n; i++) {
		for (int msk = i; msk <= n; msk = i | (msk + 1)) dsu[msk] = -1;
		for (int msk = i; msk <= n; msk = i | (msk + 1)) {
			// if (i == 1) cout << x << '\n';
			if ((par[msk] & i) == i) {
				// cout << x << " " << i << '\n';
				merge(msk, par[msk]);
				// cout << x << " " << -dsu[find(x)] << " " << i << '\n';
				res = max(res, 1ll * -dsu[find(msk)] * 1ll * i);
			}
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
	
}