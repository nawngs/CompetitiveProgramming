#include <bits/stdc++.h>

#define name "friend"
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
const int LG = 20;

int n, a[NMAX + 3], b[NMAX + 3], c1[NMAX + 3], c2[NMAX + 3], par[NMAX + 3][LG + 3], cnt[NMAX + 3][LG + 3], h[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (int j = 1; j <= LG; j++) par[u][j] = par[par[u][j - 1]][j - 1];
	for (auto id : adj[u]) {
		int v = a[id] ^ b[id] ^ u;
		if (v == par[u][0]) continue;
 		par[v][0] = u;
		dfs(v);
	}
}

void solve(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				// cout << v << " " << j << '\n';
				cnt[v][j] ++;
				v = par[v][j];
			} 
		}
	}
	if (u == v) return ;
	for (int j = LG; j >= 0; j--) {
		if (par[u][j] != par[v][j]) {
			// cout << u << " " << j << '\n';
			// cout << v << " " << j << '\n';
			cnt[u][j] ++; cnt[v][j] ++;
			u = par[u][j]; v = par[v][j];
		}
	}
	cnt[u][0] ++; cnt[v][0] ++;
	// cout << u << " " << 0 << '\n';
	// cout << v << " " << 0 << '\n';
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
		cin >> a[i] >> b[i] >> c1[i] >> c2[i];
		adj[a[i]].pb(i); adj[b[i]].pb(i);
	}
	dfs(1);
	for (int i = 1; i < n; i++) solve(i, i + 1);
	for (int j = LG; j > 0; j--) 
		for (int i = 1; i <= n; i++) {
			cnt[i][j - 1] += cnt[i][j];
			cnt[par[i][j - 1]][j - 1] += cnt[i][j];
		}
	// for (int i = 1; i <= n; i++) cout << cnt[i][0] << '\n';
	ll res = 0;
	for (int i = 1; i < n; i++) {
		if (par[b[i]][0] == a[i]) swap(b[i], a[i]);
		res += min(1ll * c2[i], 1ll * c1[i] * cnt[a[i]][0]);
	}
	cout << res;
}