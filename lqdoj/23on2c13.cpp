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
const int LOGN = __lg(NMAX) + 1;

struct Data {
	ll par, sum, MaxPre, MinPre, val;
	ll MaxSuff() {
		return sum - MinPre;
	}
	ll MinSuff() {
		return sum - MaxPre;
	}
} f[NMAX + 3][LOGN + 3];

ll n, q, a[NMAX + 3], h[NMAX + 3];

vector < int > adj[NMAX + 3];

bool MAX(ll &x, ll y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

bool MIN(ll &x, ll y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

void dfs(int u = 1) {
	h[u] = h[f[u][0].par] + 1;
	f[u][0].MaxPre = max(0ll, a[u]), f[u][0].MinPre = min(0ll, a[u]), f[u][0].val = max(0ll, a[u]);
	f[u][0].sum = a[u];
	for (int i = 1; i <= LOGN; i++) {
		Data  &res = f[u][i], x = f[u][i - 1], y = f[x.par][i - 1];
		res.par = y.par;
		res.sum = x.sum + y.sum;
		res.MaxPre = max(x.MaxPre, x.sum + y.MaxPre);
		res.MinPre = min(x.MinPre, x.sum + y.MinPre);
		res.val = max(x.val, max(y.val, x.MaxSuff() + y.MaxPre));
	}
	for (auto v : adj[u]) {
		if (v == f[u][0].par) continue;
		f[v][0].par = u;
		dfs(v);
	}
}

void update(int &v, int j, ll &res, ll &cur, ll &sum, ll &pre) {
	pre = min(pre, sum + f[v][j].MinPre); sum += f[v][j].sum;
	MAX(res, cur + f[v][j].MaxPre); MAX(res, f[v][j].val);
	cur = max(f[v][j].MaxSuff(), cur + f[v][j].sum);
	v = f[v][j].par;
}

ll calc(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	ll res = 0, curu = 0, curv = 0, sumu = 0, sumv = 0, preu = 0, prev = 0;
	if (h[u] != h[v]) {
		for (int j = LOGN; j >= 0; j--) if (h[f[v][j].par] >= h[u]) 
			update(v, j, res, curv, sumv, prev);
		
	}
	//cout << sumv << " " << prev << '\n';
	if (u == v) {
		update(v, 0, res, curv, sumv, prev);
		return res;
	}
	for (int j = LOGN; j >= 0; j--) if (f[u][j].par != 0 && f[u][j].par != f[v][j].par) {
		update(v, j, res, curv, sumv, prev);
		update(u, j, res, curu, sumu, preu);
	}
	update(v, 1, res, curv, sumv, prev); update(u, 0, res, curu, sumu, preu);
	//cout << sumu << " " << preu << " " << sumv << " " << prev << '\n';
	res = max(res, sumu + sumv - preu - prev);
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs();
	while (q--) {
		int u, v; cin >> u >> v;
		cout << calc(u, v) << '\n';
	}
}