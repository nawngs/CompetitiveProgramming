//[FINISHED]
#include <bits/stdc++.h>

#define name ""
#define int ll
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
const int INF = 1e9;
const ll LINF = 1E18;
const int NMAX = 2e5 + 5;
const int N = 1e7;
const ll MOD = 1e9;
const ll BASE = 2309;

struct Node {
	int val, l, r;
	Node() {
		val = 0, l = 0, r = 0;
	}
	Node(int x) {
		val = x; l = r = 0;
	}
};

Node it[N + 3];

int n, m, roots_a[NMAX + 3], roots_b[NMAX + 3], nnode = -1;

int build(int l, int r) {
	if (l == r) {
		it[++ nnode] = Node();
		return nnode;
	}
	int mid = (l + r) / 2, cur = ++ nnode;
	it[cur].l = build(l, mid); it[cur].r = build(mid + 1, r);
	it[cur].val = 0;
	return cur;
}

void calc(int id) {
	int x = it[id].l, y = it[id].r;
	it[id].val = (x == 0 ? 0 : it[x].val) + (y == 0 ? 0 : it[y].val);
}

int update(int node, int l, int r, int pos, int val) {
	if (l == r) {
		it[++ nnode] = Node(it[node].val + val);
		// cout << l << " " << r << " " << nnode << '\n';
		return nnode;
	}
	int mid = (l + r) / 2, cur = ++ nnode;
	if (pos <= mid) {
		it[cur].l = update(it[node].l, l, mid, pos, val);
		it[cur].r = it[node].r;
	}
	else {
		it[cur].l = it[node].l;
		it[cur].r = update(it[node].r, mid + 1, r, pos, val);
	}
	// cout << "update " << node << " " << cur << " " << l << " " << r << " " << it[cur].l << " " << it[cur].r << '\n';
	calc(cur);
	return cur;
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].val;
	int mid = (l + r) / 2;
	// cout << "query " << node << " " << l << " " << r << " " << it[node].l << " " << it[node].r << '\n';
	return query(it[node].l, l, mid, u, v) + query(it[node].r, mid + 1, r, u, v);
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	build(1, NMAX);
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2, a, b; cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		roots_a[i] = update(roots_a[i - 1], 1, NMAX, x1 + 1, a); 
		roots_a[i] = update(roots_a[i], 1, NMAX, x2 + 1, -a);
		roots_b[i] = update(roots_b[i - 1], 1, NMAX, 1, y1);
		roots_b[i] = update(roots_b[i], 1, NMAX, x1 + 1, b - y1);
		roots_b[i] = update(roots_b[i], 1, NMAX, x2 + 1, y2 - b);
	}
	int q; cin >> q;
	int ans = 0;
	for (int t = 1; t <= q; t++) {
		int l, r, x; cin >> l >> r >> x;
		//9if (t == 6236) cout << x + ans << '\n';
		x = (x + ans) % MOD;
		assert(x != 0);
		ll deltaa, deltab;
		deltaa = query(roots_a[r], 1, NMAX, 1, min(NMAX, x)) - query(roots_a[l - 1], 1, NMAX, 1, min(x, NMAX));
		deltab = query(roots_b[r], 1, NMAX, 1, min(NMAX, x))  - query(roots_b[l - 1], 1, NMAX, 1, min(NMAX, x));
		//cout << deltaa << " " << deltab << '\n';
		ans = deltaa * x + deltab;
		cout << ans << '\n';
	}
}