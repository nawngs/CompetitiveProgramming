#include <bits/stdc++.h>

#define name ""
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
const ll LINF = 1E15;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, m, dp[100003][503], a[100003];

int it[800003], lazy[800003];

void build(int node, int l, int r) {
	it[node] = lazy[node] = INF;
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r) {
	if (lazy[node] != INF) {
		it[node] = min(it[node], lazy[node]);
		if (l != r) {
			lazy[node * 2] = min(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = min(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = INF;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val); update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		update(1, 1, n, u, v, c);
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++) dp[i][j] = -LINF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int val = query(1, 1, n, i, i);
		for (int j = 0; j <= k; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);
			if (j >= val) dp[i][j] = max(dp[i][j], dp[i - 1][j - val]);
		}
	}
	ll res = -LINF;
	for (int j = 0; j <= k; j++) res = max(res, dp[n][j]);
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}