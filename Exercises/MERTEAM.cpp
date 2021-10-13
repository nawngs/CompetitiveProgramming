#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < ll, pll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, m, a[100005];

struct Dsu {
	vector < plll > par;
	void init(int n) {
		par.resize(n + 5, {0, {0, 0}});
		for (int i = 1; i <= n; i++) par[i] = {i, {a[i], a[i]}};
	}
	int find_root(int u) {
		return par[u].fi == u ? u : find_root(par[u].fi);
	}
	void join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return ;
		par[root_v].se.fi = max(par[root_v].se.fi, par[root_u].se.fi);
		par[root_v].se.se = min(par[root_v].se.se, par[root_u].se.se);
		par[root_u].fi = root_v;
 	}
	
} dsu;

int main() {
	fastflow;
	freopen("MERTEAM.INP", "r", stdin);
	freopen("MERTEAM.OUT", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];	
	dsu.init(n);
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			int y;
			cin >> y;
			int root_y = dsu.find_root(y);
			cout << (dsu.par[root_y].se.fi) << " " << dsu.par[root_y].se.se << '\n';
		}
		else {
			int y, z;
			cin >> y >> z;
			dsu.join(y, z);
		}
	}
}
