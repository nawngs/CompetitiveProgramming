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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, a[NMAX + 3];

pll it[4 * NMAX + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node].fi = it[node].se = a[l];
		return ;
	}
	build(lnode); build(rnode);
	it[node].fi = it[node * 2].fi + it[node * 2 + 1].fi;
	it[node].se = max(it[node * 2].se, it[node * 2 + 1].se);
}

void update(int node, int l, int r, int u, int v) {
	if (u < l || r < u) return ;
	if (l == r) {
		it[node].fi = it[node].se = v;
		return ;
	}
	update(lnode, u, v); update(rnode, u, v);
	it[node].fi = it[node * 2].fi + it[node * 2 + 1].fi;
	it[node].se = max(it[node * 2].se, it[node * 2 + 1].se);
}

int get(int node, int l, int r, int st, int fn, ll s) {
	if (st > fn) return n + 1;
	if (l == r) {
		if (it[node].fi >= s) return l;
		else return n + 1;
	}
	int mid = (l + r) / 2;
	int res = n + 1;
	if (it[node * 2].se >= s) res = get(lnode, st, min(mid, fn), s);
	if (res != n + 1) return res;
	if (it[node * 2 + 1].se >= s) res = get(rnode, max(st, mid + 1), fn, s);
	return res;
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0ll;
	if (u <= l && r <= v) return it[node].fi;
	return query(lnode, u, v) + query(rnode, u, v);
}

int get_ans() {
	ll id = 1, total = 0;
	while (id <= n) {
		int nxt = get(1, 1, n, id, n, total);
		if (nxt == n + 1) return -1;
		ll pre = query(1, 1, n, 1, nxt - 1);
		if (pre == query(1, 1, n, nxt, nxt)) return nxt;
		id = nxt + 1; total = query(1, 1, n, 1, nxt);
	}
	return -1;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int i, x; cin >> i >> x;
		update(1, 1, n, i, x);
		cout << get_ans() << '\n';
	}
}