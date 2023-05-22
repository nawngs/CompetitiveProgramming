#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plll pair < ll, pll >
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

ll n, m, q;

pll d[2003][2];

vector < pll > adj[2003];

bool minimize1(pll &x, const pll &y) {
	if (x.fi > y.fi) {
		x = y;
		return true;
	}
	else if (x.fi == y.fi) {
		x.se = max(x.se, y.se);
		return true;
	}
	return false;
}

bool minimize2(pll &x, const pll &y) {
	if (x.fi - x.se > y.fi - y.se) {
		x = y;
		return true;
	}
	return false;
}

void dijkstra() {
	for (int i = 1; i <= n; i++)
		d[i][0] = d[i][1] = {LINF, -LINF};
	d[1][0] = {0, -LINF};
	priority_queue < plll, vector < plll >, greater < plll > > heap;
	heap.push({LINF, {1, 0}});
	while (!heap.empty()) {
		auto x = heap.top(); heap.pop();
		ll diff = x.fi, u = x.se.fi, t = x.se.se, dist = d[u][t].fi, maxe = d[u][t].se;
		if (diff != dist - maxe) continue;
		for (auto v : adj[u]) {
			if (minimize2(d[v.fi][t], mp(dist + v.se, maxe)))
				heap.push(mp(d[v.fi][t].fi - d[v.fi][t].se, mp(v.fi, t)));
			if (t == 0) 
				if (minimize2(d[v.fi][1], mp(dist + v.se, v.se))) 
					heap.push(mp(d[v.fi][1].fi - d[v.fi][1].se, mp(v.fi, 1)));
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
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c});
	}
	dijkstra();
	while (q--) {
		ll s, t; cin >> s >> t;
		cout << min(d[s][0].fi, d[s][1].fi - d[s][1].se + t) << '\n';
	}
}