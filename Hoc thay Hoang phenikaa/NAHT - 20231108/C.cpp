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
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, k, par[N + 3], rnk[N + 3];

vector < pii > adj[N + 3];

map < int, int > G[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return ;
	if (SZE(G[u]) < SZE(G[v])) swap(u, v);
	rnk[u] += rnk[v]; par[v] = u;
	for (auto x : G[v]) if (G[u].find(x.fi) != G[u].end()) merge(G[u][x.fi], x.se);
	else G[u][x.fi] = x.se;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[v].pb({u, c});
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i; rnk[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int u = find(i);
		for (auto v : adj[i]) if (G[u].find(v.se) != G[u].end()) merge(G[u][v.se], v.fi);
		else G[u][v.se] = v.fi;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) if (i == find(i)) res += rnk[i] * (rnk[i] - 1) / 2;
	// for (int i = 1; i <= n; i++) if (i == find(i)) cout << i << " " << rnk[i] << '\n';
	cout << res;
}