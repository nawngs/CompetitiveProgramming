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
const int N = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int M = (1 << 22);

int n, par[N + 3], sze[N + 3], res[N + 3];

bool used[N + 3];

vector < pii > adj[N + 3];

int f[M];

int dfs(int u, int e) {
	sze[u] = 1;
	for (auto v : adj[u]) if (!used[v.fi] && v.fi != e) sze[u] += dfs(v.fi, u);
	return sze[u];
}

int find(int u, int e, int sz) {
	for (auto v : adj[u]) 
		if (!used[v.fi] && v.fi != e && sze[v.fi] * 2 >= sz) return find(v.fi, u, sz);
	return u;
}

void dfs(int u, int e, int road, int C, int len, bool upd) {
	if (!upd) {
		res[C] = max(res[C], len + f[road]);
		for (int i = 0; i < 22; i++) res[C] = max(res[C], len + f[road ^ (1 << i)]);
	}
	else f[road] = max(f[road], len);
	for (auto v : adj[u]) if (!used[v.fi] && v.fi != e) 
		dfs(v.fi, u, road ^ (1 << v.se), C, len + 1, upd);
}

void up(int u, int e, int road, int ance, int len) {
	res[ance] = max(res[ance], len + f[road]);
	for (int i = 0; i < 22; i++) res[ance] = max(res[ance], len + f[road ^ (1 << i)]);
	for (auto v : adj[u]) if (!used[v.fi] && v.fi != e) 
		up(v.fi, u, road ^ (1 << v.se), (u == ance && v.fi == par[u] ? v.fi : ance), len + 1);
}

void init(int u, int e, int road) {
	f[road] = -INF;
	for (auto v : adj[u]) 
		if (!used[v.fi] && v.fi != e) init(v.fi, u, road ^ (1 << v.se));
}

void centroid(int u) {
	int C = find(u, 0, dfs(u, 0));
	used[C] = 1;
	f[0] = 0;
	for (auto v : adj[C]) if (!used[v.fi] && v.fi != par[C]) {
		dfs(v.fi, C, (1 << v.se), C, 1, 0);
		dfs(v.fi, C, (1 << v.se), C, 1, 1);
	}
	for (auto v : adj[C]) if (!used[v.fi] && v.fi == par[C]) up(v.fi, C, (1 << v.se), v.fi, 1);
	for (auto v : adj[C]) if (!used[v.fi] && v.fi != par[C]) init(v.fi, C, (1 << v.se)); 
	for (auto v : adj[C]) if (!used[v.fi]) centroid(v.fi);
}

void solve(int u, int e) {
	for (auto v : adj[u]) if (v.fi != e) {
		solve(v.fi, u);
		res[u] = max(res[u], res[v.fi]);
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
	for (int i = 2; i <= n; i++) {
		char c; cin >> par[i] >> c;
		// cerr << par[i] << " " << i << " " << c << '\n';
		adj[par[i]].pb({i, c - 'a'}); adj[i].pb({par[i], c - 'a'});
	}
	for (int i = 1; i < (1 << 22); i++) f[i] = -INF;
	centroid(1);
	solve(1, 0);
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}