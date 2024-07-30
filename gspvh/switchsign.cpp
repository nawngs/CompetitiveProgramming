#include <bits/stdc++.h>

#define name "switchsign"
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

int n, q, it[6 * NMAX + 3], lazy[6 * NMAX + 3], pos[NMAX + 3]; 

// lazy: 0 la ko doi, 1 la dao nguoc, 2 la gan = -, 3 lan gan = +

pii a[NMAX + 3];

void build(int node, int l, int r) {
	lazy[node] = 0;
	if (l == r) {
		it[node] = a[l].fi;
		return ;
	}
	build(lnode); build(rnode);
}

int merge(int x, int y) {
	if (y == 2 || y == 3) return y;
	if (y == 0) return x;
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (x == 3) return 2;
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		// cout << l << " " << r << " " << lazy[node] << '\n';
		if (lazy[node] == 1) it[node] = -it[node];
		if (lazy[node] == 2) it[node] = -abs(it[node]);
		if (lazy[node] == 3) it[node] = abs(it[node]);
		if (l != r) {
			lazy[node * 2] = merge(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = merge(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = 0;
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
	update(lnode, u, v, val); update(rnode, u, v, val);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return abs(x.fi) < abs(y.fi);
	});
	for (int i = 1; i <= n; i++) pos[a[i].se] = i;
	build(1, 1, n);
	while (q--) {
		char c; cin >> c;
		int val; cin >> val;
		if (c == '<' && val >= 0) {
			int l = 1, r = n, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (abs(a[mid].fi) < abs(val)) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans != 0) update(1, 1, n, 1, ans, 1);
			if (ans < n) update(1, 1, n, ans + 1, n, 3);
		}
		if (c == '<' && val < 0) {
			int l = 1, r = n, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (abs(a[mid].fi) <= abs(val)) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans < n) update(1, 1, n, ans + 1, n, 3);
		}
		if (c == '>' && val >= 0) {
			int l = 1, r = n, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (abs(a[mid].fi) <= abs(val)) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans < n) update(1, 1, n, ans + 1, n, 2);
		} 
		if (c == '>' && val < 0) {
			int l = 1, r = n, mid, ans = 0;
			while (l <= r) {
				mid = (l + r) / 2;
				if (abs(a[mid].fi) < abs(val)) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans != 0) update(1, 1, n, 1, ans, 1);
			if (ans < n) update(1, 1, n, ans + 1, n, 2);
		}
	}
	// return 0;
	for (int i = 1; i <= n; i++) cout << query(1, 1, n, pos[i], pos[i]) << ' ';
}