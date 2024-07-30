#include <bits/stdc++.h>

#define name "kingdom"
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

int n, m, k;

vector < int > adj[NMAX + 3], a;

void dfs(int u, int e) {
	a.pb(u);
	for (auto v : adj[u]) if (v != e) dfs(v, u);
}

struct Node {
	int pre, suf, len, sub;
	Node() {
		pre = suf = len = sub = 0;
	}
} it[4 * NMAX + 3];
	
Node merge(const Node &x, const Node &y) {
	Node res;
	res.sub = max(x.sub, y.sub);
	res.sub = max(res.sub, x.suf + y.pre);
	res.len = x.len + y.len;
	res.pre = x.pre;
	if (x.pre == x.len) res.pre += y.pre;
	res.suf = y.suf;
	if (y.suf == y.len) res.suf += x.suf;
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].pre = it[node].suf = it[node].sub = 0;
		it[node].len = 1;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void add(int node, int l, int r, int u) {
	if (l == r) {
		it[node].pre = it[node].suf = it[node].sub = 1;
		return ;
	}
	int mid = (l + r) / 2;
	if (u <= mid) add(lnode, u);
	else add(rnode, u);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	// cout << u << " " << l <<  " " << r << " " << it[node].sub << '\n';
}

void erase(int node, int l, int r, int u) {
	if (l == r) {
		it[node].pre = it[node].suf = it[node].sub = 0;
		return ;
	}
	int mid = (l + r) / 2;
	if (u <= mid) erase(lnode, u);
	else erase(rnode, u);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) if (adj[i].size() == 1) {
		dfs(i, 0);
		break;
	}
	// for (auto x : a) cout << x << " ";
	// cout << '\n';
	build(1, 1, n);
	for (int i = 0; i < k; i++) add(1, 1, n, a[i]);
	int res = it[1].sub;
	for (int i = 1; i <= n - k; i++) {
		erase(1, 1, n, a[i - 1]);
		add(1, 1, n, a[i + k - 1]);
		res = max(res, it[1].sub);
	}
	cout << res;
}