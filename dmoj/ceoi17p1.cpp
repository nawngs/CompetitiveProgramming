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

int n, m;

int vs[NMAX + 3], par[NMAX + 3], cnt[NMAX + 3], f[NMAX + 3];

bool vis[NMAX + 3];

pii edges[NMAX + 3];

vector < int > adj[NMAX + 3];

char res[NMAX + 3];

void dfs(int u, int ide) {
	for (auto it : adj[u]) if (it != ide) {
		int v = edges[it].fi ^ edges[it].se ^ u;
		if (v == u) {
			res[it] = 'B';
			continue;
		}
		if (!vs[v]) {
			par[v] = it;
			vs[v] = vs[u] + 1;
			dfs(v, it);
			cnt[u] += cnt[v];
		}
		else {
			res[it] = 'B';
			if (vs[u] > vs[v]) {
				cnt[u] ++, cnt[v] --;
			}
		}
	}
}

void solve(int u, int ide) {
	vis[u] = 1;
	for (auto it : adj[u]) if (it != ide) {
		int v = edges[it].fi ^ edges[it].se ^ u;
		if (vis[v]) continue;
		solve(v, it);
		f[u] += f[v];
	}
	if (cnt[u] > 0) res[ide] = 'B';
	else {
		res[ide] = 'B';
		if (f[u] > 0) {
			if (u == edges[ide].fi) res[ide] = 'R';
			else res[ide] = 'L';
		}
		if (f[u] < 0) {
			if (u == edges[ide].fi) res[ide] = 'L';
			else res[ide] = 'R';
		}
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
	for (int i = 1; i <= n; i++) if (!vs[i]) vs[i] = 1, dfs(i, 0);
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		f[x] ++; f[y]--;
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) solve(i, 0);
	for (int i = 1; i <= m; i++) cout << res[i];
}