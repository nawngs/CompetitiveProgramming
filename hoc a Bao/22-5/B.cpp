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

int n;

pii f[500003];

vector < int > adj[500003];

vector < int > dia;

void dfs(int u, int e) {
	f[u] = {1, u};
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		if (f[u].fi < f[v].fi + 1) f[u] = {f[v].fi + 1, f[v].se};
		else if (f[u].fi == f[v].fi + 1) f[u].se = min(f[u].se, f[v].se);
	}
}

void get_ans(int u, int e) {
	cout << u << ' ';
	sort(adj[u].begin(), adj[u].end());
	for (auto v : adj[u]) {
		if (v == e) continue;
		get_ans(v, u);
	}
}

void get_res(int u, int e) {
	cout << u << " ";
	sort(adj[u].begin(), adj[u].end(), greater < int > ());
	int pos = -1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (f[v].fi == f[u].fi - 1 && pos == -1) pos = v;
	}
	reverse(adj[u].begin(), adj[u].end());
	for (auto v : adj[u]) {
		if (v == e || v == pos) continue;
		get_ans(v, u);
	}
	if (pos == -1) return ;
	get_res(pos, u);
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
	int st = f[1].se;
	dfs(f[1].se, 0);
	int fn = f[st].se;
	if (st > fn) swap(st, fn);
	dfs(f[1].se, 0);
	get_res(st, 0);
	
}