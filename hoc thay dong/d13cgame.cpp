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

int n, f[1000003];

vector < int > adj[1000003];

void dfs(int u, int e) {
	f[u] = INF;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		f[u] = min(f[u], f[v] + 1);
	}
	if (f[u] == INF) f[u] = 0;
}

int calc(int u, int e, int len) {
	if (len >= f[u]) return 1;
	int res = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		res += calc(v, u, len + 1);
	}
	return res;
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
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	cout << calc(1, 0, 0);
}