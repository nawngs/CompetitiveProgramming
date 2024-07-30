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
const int LG = 19;

int n, m, k, dsu[N + 3], res[N + 3], h[N + 3], par[N + 3][LG + 1], cnt[N + 3][LG + 1], pid[N + 3];

pii edges[N + 3], query[N + 3];

vector < int > adj[N + 3];

int find(int u) {
	return (u == dsu[u] ? u : dsu[u] = find(dsu[u]));
}
bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	dsu[v] = u;
	return true;
}

bool check(int id) {
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 1; i <= id; i++) join(edges[i].fi, edges[i].se);
	for (int i = 1; i <= k; i++) if (find(query[i].fi) != find(query[i].se)) return false;
	return true;
}

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	par[u][0] = e;
	for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
	int v;
	for (auto id : adj[u]) {
		v = edges[id].fi ^ edges[id].se ^ u;
		if (v != e) dfs(v, u), pid[v] = id;
	}
}

void LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j --) {
			 if (h[par[v][j]] >= h[u]) {
			 	cnt[v][j] ++;
			 	v = par[v][j];
			 }
		} 
	}
	if (u == v) return ;
	for (int j = LG; j >= 0; j --) {
		if (par[u][j] != par[v][j]) {
			cnt[u][j] ++;cnt[v][j] ++;
			u = par[u][j];v = par[v][j];
		}
	}
	cnt[u][0] ++;
	cnt[v][0] ++;
	return ;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		cin >> edges[i].fi >> edges[i].se;
	for (int i = 1; i <= k; i++)
		cin >> query[i].fi >> query[i].se;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 1; i <= ans; i++) if (join(edges[i].fi, edges[i].se)){
		adj[edges[i].fi].pb(i);
		adj[edges[i].se].pb(i);
		res[i] = 1;
	}
	for (int i = 1; i <= n; i++) if (h[i] == 0) dfs(i, 0);
	for (int i = 1; i <= k; i++) LCA(query[i].fi, query[i].se);
	for (int j = LG; j >= 1; j --) 
		for (int i = 1; i <= n; i++) {
			cnt[i][j - 1] += cnt[i][j];
			cnt[par[i][j - 1]][j - 1] += cnt[i][j];
		}
	for (int i = 1; i <= n; i++) if (cnt[i][0] == 0) res[pid[i]] = 0;
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
}