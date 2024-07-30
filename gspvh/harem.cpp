//[UNFINISHED]
#include <bits/stdc++.h>

#define name "harem"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, deg[NMAX + 3];

pii a[NMAX + 3];

vector < int > topo, res, adj[NMAX + 3];

bool check(int x) {
	topo.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		deg[i] = 0;
	}
	for (int i = 1; i <= x; i++) {
		adj[a[i].fi].pb(a[i].se);
		deg[a[i].se] ++;
	}
	for (int i = 1; i <= n; i++) if (!deg[i]) {
		if (topo.size()) return false;
		topo.pb(i);
	}
	if (!topo.size()) return false;
	for (int i = 2; i <= n; i++) {
		int u = topo.back();
		for (auto v : adj[u]) {
			deg[v] --;
			if (deg[v] == 0) topo.pb(v);
		}
		if (SZE(topo) != i) return false;
	}
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			res = topo;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
	if (ans != -1) for (auto x : res) cout << x << " ";
	
}