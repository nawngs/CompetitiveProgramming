#include <bits/stdc++.h>

#define name "dfs"
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
const int NMAX = 4e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, a[NMAX + 3], cnt[NMAX + 3], sze[NMAX + 3], f[NMAX + 3], up[NMAX + 3], x, b[NMAX + 3];

pii g[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u, int e) {
	sze[u] = 1; cnt[u] = (a[u] >= x);
	f[u] = up[u] = 0; g[u] = {0, 0};
	for (auto v : adj[u]) if (v != e) {
		dfs(v, u);
		sze[u] += sze[v]; cnt[u] += cnt[v];
		if (sze[v] == cnt[v]) f[u] += sze[v];
		else {
			if (f[v] + g[v].fi > g[u].se) g[u].se = f[v] + g[v].fi;
			if (g[u].se > g[u].fi) swap(g[u].se, g[u].fi);
		}
	}
	if (a[u] < x) {
		f[u] = 0;
		g[u] = {0, 0};
	}
	else f[u] ++;
}

void dfs2(int u, int e) {
	for (auto v : adj[u]) if (v != e) {
		if (a[u] >= x) {
			if (up[u] == n - sze[u]) {
				up[v] = up[u] + f[u] + g[u].fi;
				if (sze[v] == cnt[v]) up[v] -= cnt[v];
				else if (g[u].fi == f[v] + g[v].fi) up[v] = up[v] - g[u].fi + g[u].se;
			}
			else {
				int temp = f[u];
				if (sze[v] == cnt[v]) {
					temp -= cnt[v];
					up[v] = temp + max(up[u], g[u].fi);
				}
				else {
					if (g[u].fi != f[v] + g[v].fi) up[v] = temp + max(up[u], g[u].fi);
					else up[v] = temp + max(up[u], g[u].se);
				}
			}
		}
		else up[v] = 0;
		dfs2(v, u);
	} 
}

bool check() {	
	dfs(1, 0); dfs2(1, 0);
	int temp;
	for (int v = 1; v <= n; v++) {
		temp = f[v];
		if (up[v] == n - cnt[v]) temp += g[v].fi + up[v];
		else temp += max(up[v], g[v].fi);
		if (temp >= k) return true;
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	int l = 1, r = n, ans, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		x = b[mid];
		if (check()) {
			ans = x;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}