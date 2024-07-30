//[UNFINISHED]
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
const int NMAX = 5E4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, children[NMAX + 3], depth[NMAX + 3];

ll res = 0, up[NMAX + 3], down[NMAX + 3], pw[NMAX + 3];

bool used[NMAX + 3];

vector < int > adj[NMAX + 3];	

map < int, int > cnt;

string s;

int dfs(int u, int e = 0) {
	children[u] = 1;
	for (auto v : adj[u]) if (v != e && !used[v]) 
		children[u] += dfs(v, u);
	return children[u];
}

int get(int u, int sze, int e = 0) {
	for (auto v : adj[u]) if (v != e && !used[v]) {
		if (children[v] * 2 > sze) return get(v, sze, u);
	}
	return u;
}

void centroid(int u = 1) {
	int C = get(u, dfs(u)); used[C] = 1;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s; s = ' ' + s;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * BASE) % MOD;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	//centroid();
}