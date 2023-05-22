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

int n, m, in[100003], low[100003], timer = 0, dem = 0;

ll cnt = 0;

pii edges[100003];

vector < int > adj[100003];

bool is_bridge[100003], vs[100003];

void dfs(int u, int e) {
	in[u] = low[u] = ++ timer;
	for (auto i : adj[u]) {
		int v = edges[i].fi + edges[i].se - u;
		if (v == e) continue;
		if (!in[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (in[v] == low[v]) is_bridge[i] = true;
		}
		else low[u] = min(low[u], in[v]);
	}
}

void dfs2(int u, int e) {
	vs[u] = 1;
	cnt ++;
	for (auto v : adj[u]) {
		if (v == e) continue; 
		dem ++;
		dfs2(v, u);
	}
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
		cin >> edges[i].fi >> edges[i].se;
		adj[edges[i].fi].pb(i); adj[edges[i].se].pb(i);
	}
	for (int i = 1; i <= n; i++)
		if (!in[i]) dfs(i, 0);
	for (int i = 1; i <= n; i++) 
		adj[i].clear();
	for (int i = 1; i <= m; i++) {
		if (!is_bridge[i]) continue;
		adj[edges[i].fi].pb(edges[i].se); adj[edges[i].se].pb(edges[i].fi);
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (vs[i]) continue;
		cnt = 0, dem = 0, dfs2(i, 0);
		res = res + cnt * (cnt - 1) / 2 - dem;
	}
	cout << res;
}