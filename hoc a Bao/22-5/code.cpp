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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3], up[NMAX + 3], down[NMAX + 3], ans = 1, it[4 * NMAX + 3];

vector < int > adj[NMAX + 3];

stack < int > st;

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (a[u] <= a[v]) up[v] = up[u] + 1;
		dfs(v, u);
		if (a[u] <= a[v]) down[u] = max(down[u], down[v] + 1);
	}
}

void add(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		st.push(it[node]);
		it[node] = max(it[node], val);
		return ;
	}
	add(lnode, pos, val); add(rnode, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void remove(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = st.top();
		st.pop();
		return ;
	}
	remove(lnode, pos); remove(rnode, pos);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return max(query(lnode, u, v), query(rnode, u, v));
}

void get_res(int u, int e) {
	ans = max(ans, query(1, 1, n, 1, a[u]) + down[u]);
	add(1, 1, n, a[u], up[u]);
	for (auto v : adj[u]) {
		if (v == e) continue;
		get_res(v, u);
	}
	remove(1, 1, n, a[u]);
}

void sol() {
	cin >> n;
	vector < int > val;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		cin >> a[i];
		val.pb(a[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
		up[i] = down[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	ans = 1;
	get_res(1, 0);
	cout << (ans < 2 ? 0 : ans) << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();

}