#include <bits/stdc++.h>

#define name "runner"
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

int n, par[400003][20], h[400003];

vector < int > adj[400003];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (int i = 1; i <= 19; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u; dfs(v);
	}
}

int cnt[400003];

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) {
		if (h[par[v][i]] >= h[u]) 
			v = par[v][i];
	}
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) {
		if (par[u][i] != par[v][i]) 
			u = par[u][i], v = par[v][i];
	}
	return par[u][0];
}

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
	}
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
	dfs(1);
	for (int i = 1; i < n; i++) {
		cnt[i] ++; cnt[i + 1] ++;
		int c = LCA(i, i + 1);
		cnt[c] --; cnt[par[c][0]] --;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << cnt[i] << '\n';
}