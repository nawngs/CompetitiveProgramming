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
const int N = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, root[N + 3], nnode;

vector < tuple < int, int, int > > a;

struct Node {
	int v, l, r;
	Node() {
		v = 0;
		l = r = 0;
	}
} it[N * 80 + 3];

int build(int node, int l, int r) {
	if (l == r) {
		it[++ nnode] = Node();
		return nnode;
	}
	int id = ++ nnode;
	it[id].l = build(lnode); it[id].r = build(rnode);
	return id;
}

int update(int node, int l, int r, int pos, int val) {
	if (l == r) {
		it[++nnode].v = max(it[node].v, val);
		return nnode;
	}
	int mid = (l + r) / 2, id = ++ nnode;
	it[id] = it[node];
	if (pos <= mid) it[id].l = update(it[node].l, l, mid, pos, val);
	else it[id].r = update(it[node].r, mid + 1, r, pos, val);
	it[id].v = min(it[it[id].l].v, it[it[id].r].v);
	return id;
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node].v;
	int mid = (l + r) / 2;
	return min(query(it[node].l, l, mid, u, v), query(it[node].r, mid + 1, r, u, v));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int l, r, p; cin >> l >> r >> p;
		a.pb({r, l, p});
	}
	sort(a.begin(), a.end());
	root[k] = build(1, 1, n);
	for (int i = 0; i < k; i++) {
		int l, r, p; tie(r, l, p) = a[i];
		// cerr << l << " " << r << " " << p << '\n';
		root[i] = update(root[i - 1], 1, n, p, l);
	}
	while(m--) {
		int lo, hi, x, y; cin >> lo >> hi >> x >> y;
		auto it = lower_bound(a.begin(), a.end(), tuple< int, int, int >(y + 1, 0, 0)) - a.begin(); it --;
		// cout << it << '\n';
		// for (int i = lo; i <= hi; i++) cout << query(root[it], 1, n, i, i) << ' ';
		// cout << '\n';
		cout << (query(root[it], 1, n, lo, hi) >= x ? "yes" : "no");
		cout << endl;
	}
}