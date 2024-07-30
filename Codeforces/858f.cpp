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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, vs[NMAX + 3];

vector < int > adj[NMAX + 3], f[NMAX + 3];

vector < tuple < int, int, int > > res;

void dfs(int u, int e) {
	for (auto v : adj[u]) if (v != e) {
		if (!vs[v]) {
			vs[v] = vs[u] + 1;
			dfs(v, u);
		}
		else if (vs[u] > vs[v]) f[u].pb(v);
	}
	for (int i = 0; i < SZE(f[u]) - 1; i+=2) 
		res.emplace_back(f[u][i], u, f[u][i + 1]);
	if (e && SZE(f[u]) % 2 == 1)
		res.emplace_back(e, u, f[u].back());
	else f[e].pb(u);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		vs[i] = 1; dfs(i, 0);
	}
	cout << res.size() << '\n';
	for (auto it : res) {
		int a, b, c; tie(a, b, c) = it;
		cout << a << " " << b << " " << c << '\n';
	}
}