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

int n, m, res = 0;

bool vs[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	cout << adj[u].size() << '\n';
	res += (adj[u].size() & 1);
	vs[u] = 1;
 	for (auto v : adj[u]) if (!vs[v]) dfs(v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int u, v, c; cin >> u >> v >> c;
		if (!c) continue;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) dfs(i);
	cout << res / 2;
	
}