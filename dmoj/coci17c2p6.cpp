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
const ll LINF = 1E18;
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	int val;
	vector < pii > pre, suff;
	Node() {
		val = 0;
		pre.clear(); suff.clear();
	}
};

int n, q, a[NMAX + 3];

Node it[4 * NMAX + 3];

Node merge(Node const &x, Node const &y) {
	Node res;
	res.val = x.val + y.val;
	int cnt = 0;
	for (auto v : x.suff) cnt += v.se;
	int cur = SZE(x.suff) - 1;
	for (auto v : y.pre) {
		while (cur > 0 && __gcd(x.suff[cur].fi, v.fi) == 1) {
			cnt -= x.suff[cur].se;
			cur --;
		}
		if (__gcd(x.suff[cur].fi, v.fi) != 1) res.val += cnt * v.se;
	}
	res.pre = x.pre;
	for (auto v : y.pre) {
		int nxt = __gcd(res.pre.back().fi, v.fi);
		if (nxt == res.pre.back().fi) res.pre.back().se += v.se;
		else res.pre.pb({nxt, v.se});
	}
	res.suff = y.suff;
	for (auto v : x.suff) {
		int nxt = __gcd(res.suff.back().fi, v.fi);
		if (nxt == res.suff.back().fi) res.suff.back().se += v.se;
		else res.suff.pb({nxt, v.se});
	}
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].val = (a[l] != 1);
		it[node].pre.pb({a[l], 1}); it[node].suff.pb({a[r], 1});
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].val = (val != 1);
		it[node].pre[0].fi = val; it[node].suff[0].fi = val;
		return ;
	}
	update(lnode, pos, val); update(rnode, pos, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return Node();
	if (u <= l && r <= v) return it[node];
	Node lval = query(lnode, u, v), rval = query(rnode, u, v);
	if (!SZE(lval.pre)) return rval;
	if (!SZE(rval.pre)) return lval;
	// cout << "HAHA " << l << " " << (l + r) / 2 << " " << lval.val << '\n';
	// for (auto x : lval.suff) cout << x.fi << " " << x.se << '\n';
	// cout << "HAHA " << (l + r) / 2 + 1 << " " << r << " " << rval.val << '\n';
	// for (auto x : rval.pre) cout << x.fi << " " << x.se << '\n';
	return merge(lval, rval);
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
	for (int i = 1; i <= q; i++) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 1) update(1, 1, n, l, r);
		else cout << query(1, 1, n, l, r).val << '\n';
	}
}