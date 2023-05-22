#include <bits/stdc++.h>

#define int ll
#define name "network"
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

ll n, k, m, c[100003], cnt_comp = 0;

bool vs[100003];

vector < int > group[100003], adj[100003], comp[100003];

void dfs(int u, int id) {
	vs[u] = 1;
	for (auto v : group[u]) comp[id].push_back(v);
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(v, id);
	}
}

void umax(pii &x, pii y) {
	if (x.fi < y.fi) x = y;
}

pair<int,int> find_furthest(int u, int pa) { //its a tree bro
    pair<int,int> res(-1,u);
    for (auto v : adj[u]) if (v != pa)
        umax(res, find_furthest(v,u));
    ++res.first;
    return res;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= k; i++) {
		int k; cin >> k;
		group[i].resize(k);
		for (auto &x : group[i]) cin >> x;
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= k; i++) 
		if (sz(adj[i]) && !vs[i]) 
			dfs(i, ++ cnt_comp);
	for (int i = 1; i <= k; i++) 
		adj[i].clear();
	vector < pii > edges;
	ll cnte = 0, maxl = 0;
	for (int i = 1; i <= cnt_comp; i++) {
		sort(comp[i].begin(), comp[i].end(), [&](int &x, int &y) {
			return c[x] > c[y];
		});
		int j = 1;
		for (auto x : comp[i]) {
			if (comp[i][j] == x) j ++;
			while (c[x] && j < sz(comp[i])) {
				edges.push_back({x, comp[i][j]});
				adj[x].push_back(comp[i][j]); adj[comp[i][j]].push_back(x);
				c[x] --;
				c[comp[i][j]] --;
				j ++;
			}
			if (j == sz(comp[i])) break;
		}
		int u = comp[i][0];
		u = find_furthest(u, u).se;
		maxl = max(maxl, find_furthest(u, u).fi);
	}
	cnte = sz(edges);
	cout << n * cnte + maxl << '\n';
	for (auto x : edges) cout << x.fi << " " << x.se << '\n';
}