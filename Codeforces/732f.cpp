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
const int N = 4e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, num[N + 3], low[N + 3], timer = 0, scc = 0, cnt[N + 3], idx[N + 3];

bool vs[N + 3];

pii ed[N + 3], res[N + 3];

vector < int > G[N + 3], adj[N + 3], bridge[N + 3], ver[N + 3];

void dfs(int u, int p) {
	num[u] = low[u] = ++ timer;
	for (auto id : G[u]) if (id != p) {
		int v = ed[id].fi ^ ed[id].se ^ u;
		if (!num[v]) {
			dfs(v, id);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) bridge[u].pb(v);
			else res[id] = {u, v}, adj[u].pb(v);
		}
		else {
			res[id] = {v, u};
			adj[v].pb(u);
			low[u] = min(low[u], num[v]);
		}
	}
}

void dfs(int u) {
	ver[scc].pb(u);
	vs[u] = 1;
	cnt[scc] ++; idx[u] = scc;
	for (auto v : adj[u]) if (!vs[v]) dfs(v);
}

void solve(int cur) {
	vector < int > vec;
	vs[cur] = 1;
	for (auto u : ver[cur]) {
		for (auto id : G[u]) {
			int v = ed[id].fi ^ ed[id].se ^ u;
			if (vs[idx[v]]) continue;
			res[id] = {v, u};
			vec.pb(idx[v]);
		}
	}
	for (auto v : vec) if (!vs[v]) solve(v);
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
		cin >> ed[i].fi >> ed[i].se;
		G[ed[i].fi].pb(i); G[ed[i].se].pb(i);
	}
	dfs(1, 0);
	int pos = -1;
	for (int i = 1; i <= n; i++) if (!vs[i]) {
 		++ scc; dfs(i);
 		if (pos == -1 || cnt[pos] < cnt[scc]) pos = scc;
	}
	cout << cnt[pos] << '\n';
	memset(vs, 0, sizeof(vs));
	solve(pos);
	for (int i = 1; i <= m; i++) cout << res[i].fi << " " << res[i].se << '\n';
}