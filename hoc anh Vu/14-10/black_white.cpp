#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int l, r, t;
} a[200003];

struct Segment_Tree {
	pii it[1600003];
	int lazy[1600003];
	void build(int node, int l, int r) {
		it[node].fi = it[node].se = lazy[node] = 0;
		if (l == r) return ;
		int mid = (l + r) / 2;
		build(node * 2, l, mid);
		build(node * 2 + 1, mid + 1, r);
	}
	void update_node(int node, int l, int r) {
		if (lazy[node] != 0) {
			it[node].se += lazy[node];
			if (l != r) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	pii merge(pii x, pii y) {
		if (x.fi + x.se > y.fi + y.se) return x;
		else return y;
	}
	void update(int node, int l, int r, int u, int v, int val) {
		update_node(node, l, r);
		if (v < l || r < u) return ;
		if (u <= l && r <= v) {
			lazy[node] = val;
			update_node(node, l, r);
			return ;
		}
		int mid = (l + r) / 2;
		update(node * 2, l, mid, u, v, val);
		update(node * 2 + 1, mid + 1, r, u, v, val);
		it[node] = merge(it[node * 2], it[node * 2 + 1]);
	}
	void update(int node, int l, int r, int pos, int val) {
		update_node(node, l, r);
		if (pos < l || pos > r) return ;
		if (l == r) {
			it[node].fi = max(it[node].fi, val);
			return ;
		}
		int mid = (l + r) / 2;
		update(node * 2, l, mid, pos, val);
		update(node * 2 + 1, mid + 1, r, pos, val);
		it[node] = merge(it[node * 2], it[node * 2 + 1]);
	}
	int query(int node, int l, int r, int u, int v) {
		update_node(node, l, r);
		if (v < l || r < u) return 0;
		//if (u == 1 && v == 3) cout << l << " " << r << " " << it[node].fi + it[node].se << '\n';
		if (u <= l && r <= v) return it[node].fi + it[node].se;
		int mid = (l + r) / 2;
		return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
	}
} st[3];

int n;

int main() {
	fast;
	//fre();
	cin >> n;
	vector < ll > val;
	val.push_back(-INF);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].l >> a[i].r >> a[i].t;
		val.push_back(a[i].l);
		val.push_back(a[i].r);
	}
	sort(a + 1, a + n + 1, [&](Data &x, Data &y) {
		return x.r < y.r;
	});
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= n; i++) {
		a[i].l = lower_bound(val.begin(), val.end(), a[i].l) - val.begin() + 1;
		a[i].r = lower_bound(val.begin(), val.end(), a[i].r) - val.begin() + 1;
	}
	int res = 0;
	st[1].build(1, 1, val.size());
	st[2].build(1, 1, val.size());
	for (int i = 1; i <= n; i++) {
		int temp = st[3 - a[i].t].query(1, 1, val.size(), 1, a[i].l - 1) + 1;
		//cout << a[i].l << " " << a[i].r << " " << a[i].t << " " << temp << " " << st[3 - a[i].t].query(1, 1, val.size(), 1, 1) << '\n';
		res = max(res, temp);
		st[a[i].t].update(1, 1, val.size(), a[i].r, temp);
		st[3 - a[i].t].update(1, 1, val.size(), 1, a[i].l - 1, 1);
	}
	cout << res;
}
