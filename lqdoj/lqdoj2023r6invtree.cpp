#include <bits/stdc++.h>

#define name "invtree"
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, root, sz[NMAX + 3], par[NMAX + 3];

bool big[NMAX + 3];

ll res = 0;

vector < int > vec[NMAX + 3];

vector < int > adj[NMAX + 3];

int bit[NMAX + 3];

void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int getSum(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int dfs(int u, int e) {
	res += getSum(n) - getSum(u);
	update(u, 1);
	sz[u] = 1; par[u] = e;
	for (auto v : adj[u]) if (v != e) sz[u] += dfs(v, u);
	update(u, -1);
	return sz[u];
}

pll merge(const pll &x, const pll &y) {
	pll res = {0, 0};
	res = {x.fi + y.fi, x.se + y.se};
	return res;
}

pll calc(int u, int sze) {
	pll ans = {0, 0};
	ans.fi = getSum(u - 1);
	ans.se = sze - ans.fi;
	for (auto v : adj[u]) if (v != par[u]) ans = merge(ans, calc(v, sze));
	return ans;
}

void add(int u, int val) {
	update(u, val);
	for (auto v : adj[u]) if (v != par[u] && !big[v]) add(v, val);
}

void solve(int u, bool keep) {
	int bigchild = -1;
	for (auto v : adj[u]) if (v != par[u] && (bigchild == -1 || sz[v] > sz[bigchild])) bigchild = v;
	for (auto v : adj[u]) if (v != par[u] && v != bigchild) solve(v, 0);
	if (bigchild != -1) {
		solve(bigchild, 1);
		big[bigchild] = 1;
	}
	pll temp;
	for (auto v : adj[u]) if (v != par[u] && v != bigchild) temp = calc(v, sz[bigchild]);
	res += min(temp.fi, temp.se);
	add(u, 1);
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
	cin >> n >> root;
	for (int i = 2; i <= n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(root, 0); solve(root, 1);
	cout << res;
}