//[UNFINISHED]
#include <bits/stdc++.h>

#define int ll
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
const ll LINF = 1E16;
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, a[NMAX + 3];

ll lazy[8 * NMAX + 3];

int res[NMAX + 3];

pll it[8 * NMAX + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = {a[l], l};
		return ;
	}
	build(lnode); build(rnode);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].fi += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int pos, ll val) {
	update(node, l, r);
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].fi = val;
		return ;
	}
	update(lnode, pos, val); update(rnode, pos, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

pll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return {LINF, LINF};
	if (u <= l && r <= v) return it[node];
	return min(query(lnode, u, v), query(rnode, u, v));
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	 cin >> n >> q;
	 for (int i = 1; i <= n; i++) cin >> a[i];
	 build(1, 1, n);
	 memset(res, 255, sizeof res);
	 for (int t = 1; t <= q; t++) {
	 	int l, r, s; cin >> l >> r >> s;
	 	while (1) {
	 		pii temp = query(1, 1, n, l, r);
	 		if (temp.fi > s) break;
	 		res[temp.se] = t;
	 		update(1, 1, n, temp.se, LINF); 
	 	}
	 	update(1, 1, n, l, r, -s);
	 }
	 for (int i = 1; i <= n; i++) {
	 	int ans = 0;
	 	for (int j = i; j <= n; j+=i) ans = max(ans, (res[j] == -1 ? INF : res[j]));
	 	cout << (ans == INF ? -1 : ans) << ' ';
	 }
}