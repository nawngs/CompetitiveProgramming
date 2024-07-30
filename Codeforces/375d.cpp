//[UNFINISHED]
#include <bits/stdc++.h>

#define name "tcq"
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

int n, a[NMAX + 3], q, sz[NMAX + 3], cnt[NMAX + 3], res[NMAX + 3], par[NMAX + 3];

bool big[NMAX + 3];

vector < pii > query[NMAX + 3];

vector < int > adj[NMAX + 3];

int bit[NMAX + 5];

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

int dfs1(int u, int e) {
	sz[u] = 1; par[u] = e;
	for (auto v : adj[u]) if (v != e) sz[u] += dfs1(v, u);
	return sz[u];
}

void add(int u, int val) {
	if (cnt[a[u]] != n + 1) update(cnt[a[u]], -1);
	cnt[a[u]] -= val;
	if (cnt[a[u]] != n + 1) update(cnt[a[u]], 1);
	for (auto v : adj[u]) if (v != par[u] && !big[v]) add(v, val);
}

void dfs(int u, bool keep) {
	int bigchild = -1;
	for (auto v : adj[u]) if (v != par[u] && (bigchild == -1 || sz[v] > sz[bigchild])) bigchild = v;
	for (auto v : adj[u]) if (v != par[u] && v != bigchild) dfs(v, 0);
	if (bigchild != -1) {
		dfs(bigchild, 1); 
		big[bigchild] = 1;
	}
	add(u, 1);
	for (auto x : query[u]) res[x.se] = getSum(n - x.fi + 1);
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
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = n + 1;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= q; i++) {
		int u, k; cin >> u >> k;
		query[u].pb({k, i});
	}
	dfs1(1, 0);
	dfs(1, 1);
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}