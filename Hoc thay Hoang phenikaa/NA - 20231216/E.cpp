#include <bits/stdc++.h>

#define name ""
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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, in[N + 3], out[N + 3], timer = 0, sze[N + 3], it[4 * N + 3], res[N + 3];

pii q[N + 3];

bool big[N + 3];

vector < int > adj[N + 3];

void update(int node, int l, int r, int pos, int v) {
	if (pos < l || r < pos) return ;
	it[node] += v;
	if (l == r) return ;
	update(lnode, pos, v); update(rnode, pos, v);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

int dfs(int u) {
	sze[u] = 1;
	in[u] = out[u] = ++ timer;
	for (auto v : adj[u]) sze[u] += dfs(v);
	out[u] = timer;
	return sze[u];
}

void add(int u, int val) {
	update(1, 1, n, q[u].fi, val);
	for (auto v : adj[u]) if (!big[v]) add(v, val);
}

void solve(int u, bool keep) {
	int bigchild = -1;
	for (auto v : adj[u]) if (bigchild == -1 || sze[v] > sze[bigchild]) bigchild = v;
	for (auto v : adj[u]) if (v != bigchild) solve(v, 0);
	if (bigchild != -1) {
		solve(bigchild, 1); 
		big[bigchild] = 1;
	}
	add(u, 1);
	res[u] = query(1, 1, n, q[u].fi, q[u].se);
	if (bigchild != -1) big[bigchild] = 0;
	if (!keep) add(u, -1);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		adj[u].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) q[i] = {in[i], out[i]}, adj[i].clear();
	for (int i = 2; i <= n; i++) {
		int u; cin >> u;
		adj[u].pb(i);
	}
	timer = 0; dfs(1);
	solve(1, 1);
	for (int i = 1; i <= n; i++) cout << res[i] - 1 << ' ';
}