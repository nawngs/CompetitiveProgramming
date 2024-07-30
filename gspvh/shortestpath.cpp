//[UNFINISHED]
#include <bits/stdc++.h>

#define name "shortestpath"
#define int ll
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
const ll LINF2 = 1E16;
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, p, scc = 0, id[NMAX + 3], deg[NMAX + 3], uu, vv, cc;

ll d[NMAX + 3];

pii a[3 * NMAX + 3];

vector < pll > adj[NMAX + 3], adj2[NMAX + 3];

vector < int > inscc[NMAX + 3];

bool vs[NMAX + 3];

void dfs(int u) {
	vs[u] = 1;
	id[u] = scc;
	inscc[scc].pb(u);
	for (auto v : adj[u]) if (!vs[v.fi]) dfs(v.fi);
}

bool minimize(ll &x, ll y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> p;
	for (int i = 1; i <= m; i++) {
		cin >> uu >> vv >> cc;
		adj[uu].pb(mp(vv, cc)); adj[vv].pb(mp(uu, cc));
	}
	for (int i = 1; i <= n; i++) if (!id[i]) {
		scc ++;
		dfs(i);
	}
	for (int i = 1; i <= p; i++) {
		cin >> a[i].fi >> a[i].se >> cc;
		adj2[id[a[i].fi]].pb(mp(i, cc));
		deg[id[a[i].se]] ++;
	}
	for (int i = 1; i <= n; i++) d[i] = LINF;
	d[1] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	vector < int > topo;
	queue < int > q;
	topo.clear();
	while (q.size()) q.pop();
	for (int i = 1; i <= scc; i++) if (deg[i] == 0) {
		q.push(i);
		topo.pb(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto x : adj2[u]) {
			int v = a[x.fi].se; deg[id[v]] --;
			if (deg[id[v]] == 0) {
				q.push(id[v]);
				topo.pb(id[v]);
			}
		}
	}
	for (auto idscc : topo) {
		for (auto x : inscc[idscc]) heap.push({d[x], x});
		while (!heap.empty()) {
			auto u = heap.top(); heap.pop();
			if (u.fi != d[u.se]) continue;
			for (auto v : adj[u.se]) if (minimize(d[v.fi], u.fi + v.se)) heap.push({d[v.fi], v.fi});
		}
		for (auto idx : adj2[idscc]) {
			int u = a[idx.fi].fi, v = a[idx.fi].se;
			minimize(d[v], d[u] + idx.se);
		}
	}
	for (int i = 1; i <= n; i++) cout << (d[i] > LINF2 ? -1 : d[i]) << " ";
}