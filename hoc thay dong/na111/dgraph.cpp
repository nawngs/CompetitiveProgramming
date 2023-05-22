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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, par[NMAX + 3], d[NMAX + 3], f[NMAX + 3], dem[NMAX + 3];

pii a[NMAX + 3];

vector < pii > adj[NMAX + 3];

bool check(int x, int y) {
	if (sz(adj[x]) != sz(adj[y])) return sz(adj[x]) > sz(adj[y]);
	return x > y;
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
		cin >> a[i].fi >> a[i].se;
		adj[a[i].fi].push_back({a[i].se, i}); adj[a[i].se].push_back({a[i].fi, i});
	}
	for (int u = 1; u <= n; u++) 
		sort(adj[u].begin(), adj[u].end(), [&](pii &x, pii &y) {
			if (sz(adj[x.fi]) != sz(adj[y.fi])) return sz(adj[x.fi]) > sz(adj[y.fi]);
			return x.fi > y.fi;
		});
	for (int u = 1; u <= n; u++) {
		for (auto v : adj[u]) {
			if (!check(v.fi, u)) break;
			d[v.fi] = u;
			f[v.fi] = v.se;
		}
		for (auto v : adj[u]) {
			if (!check(v.fi, u)) break;
			for (auto z : adj[v.fi]) {
				if (!check(z.fi, v.fi)) break;
				if (d[z.fi] == u) {
					dem[v.se] ++;
					dem[z.se] ++;
					dem[f[z.fi]] ++;
				}
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		res = (res + 1ll * dem[i] * 1ll * (dem[i] - 1) / 2);
	}
	cout << res;
}
