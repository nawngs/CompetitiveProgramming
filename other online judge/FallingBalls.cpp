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
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int l, r, y;
	bool operator < (const Data &x) {
		return y < x.y;
	}
} a[100003];

int n, q, it[800003], lazy[800003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		//cout << l << " " << r << " " << it[node] << '\n';
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
}

void update_node(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] = lazy[node];
		if (l < r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = 0;
	}
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
}

int query(int node, int l, int r, int pos) {
	update_node(node, l, r);
	if (pos < l || pos > r) return 0;
	if (pos == l && pos == r) return it[node];
	return query(node * 2, l, (l + r) / 2, pos) + query(node * 2 + 1, (l + r) / 2 + 1, r, pos);
}

int main() {
	fast;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i]. l >> a[i].r >> a[i].y;
	sort(a + 1, a + n + 1);
	build_tree(1, 1, nmax);
	for (int i = 1; i <= n; i++) {
		int mid = (a[i].l + a[i].r) / 2;
		update(1, 1, nmax, a[i].l, mid, query(1, 1, nmax, a[i].l));
		update(1, 1, nmax, mid + 1, a[i].r, query(1, 1, nmax, a[i].r));
	}
	while (q--) {
		int x;
		cin >> x;
		cout << query(1, 1, nmax, x) << '\n';
	}
}
