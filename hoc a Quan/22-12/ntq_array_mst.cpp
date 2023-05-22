#include <bits/stdc++.h>

#define name ""
#define test "test"
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

ll n, a[NMAX + 3], par[NMAX + 3];

pll f[NMAX + 3], g[NMAX + 3];

vector < int > comp[NMAX + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	if (comp[u].size() < comp[v].size()) swap(u, v);
	for (auto x : comp[v]) comp[u].push_back(x);
	par[v] = u;
	return true;
}

int main() {
	//fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = i;
		comp[i].push_back(i);
	}
	a[0] = -LINF; f[0] = {0, 0};
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (find(f[i].fi) == find(i)) {
			if (a[f[i].fi] < a[i])
				f[i].fi = i;
			continue;
		}
		if (a[f[i].se] < a[i]) f[i].se = i;
		if (a[f[i].se] > a[f[i].fi]) swap(f[i].fi, f[i].se);
	}
	a[n + 1] = LINF; g[n + 1] = {n + 1, n + 1};
	for (int i = n; i >= 1; i--) {
		g[i] = g[i + 1];
		if (find(g[i].fi) == find(i)) {
			if (a[g[i].fi] > a[i]) 
				g[i].fi = i;
			continue;
		}
		if (a[g[i].se] > a[i]) g[i].se = i;
		if (a[g[i].se] < a[g[i].fi]) swap(g[i].fi, g[i].se);
	}
	stack < pll > temp;
	ll res = 0;
	while (sz(comp[find(1)]) != n) {
		for (int i = 1; i <= n; i++) {
			int u = find(i);
			if (u != i) continue;

			ll val = LINF;
			pll ans;
			for (auto x : comp[u]) {
				pll val1 = {a[x] - a[f[x - 1].fi], f[x - 1].fi};
				if (find(f[x - 1].fi) == u) 
					val1 = {a[x] - a[f[x - 1].se], f[x - 1].se};
				pll val2 = {a[g[x + 1].fi] - a[x], g[x + 1].fi};
				if (find(g[x + 1].fi) == u) 
					val2 = {a[g[x + 1].se] - a[x], g[x + 1].se};
				if (val1.fi < val) {
					val = val1.fi;
					ans = {x, val1.se};
				}
				if (val2.fi < val) {
					val = val2.fi;
					ans = {x, val2.se};
				}
			}
			temp.push(ans);
		}
		while (temp.size()) {
			pll x = temp.top(); temp.pop();
			if (join(x.fi, x.se)) res += a[max(x.fi, x.se)] - a[min(x.fi, x.se)];
		}
		a[0] = -LINF; f[0] = {0, 0};
		for (int i = 1; i <= n; i++) {
			//f[i] = f[i - 1];
			if (find(f[i].fi) == find(i)) {
				if (a[f[i].fi] < a[i])
					f[i].fi = i;
				continue;
			}
			if (a[f[i].se] < a[i]) f[i].se = i;
			if (a[f[i].se] > a[f[i].fi]) swap(f[i].fi, f[i].se);
		}
		a[n + 1] = LINF; g[n + 1] = {n + 1, n + 1};
		for (int i = n; i >= 1; i--) {
			//g[i] = g[i + 1];
			if (find(g[i].fi) == find(i)) {
				if (a[g[i].fi] > a[i]) 
					g[i].fi = i;
				continue;
			}
			if (a[g[i].se] > a[i]) g[i].se = i;
			if (a[g[i].se] > a[g[i].fi]) swap(g[i].fi, g[i].se);
		}
	}
	cout << res << '\n';
}