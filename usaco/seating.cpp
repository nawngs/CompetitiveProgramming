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

const string NAME = "seating";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m;

int lazy[3000002];

struct Node {
	int sze;
	int sub, subl, subr, possub;
} it[3000002];

Node merge(Node x, Node y, int r) {
	Node res;
	res.sze = x.sze + y.sze;
	res.sub = max(x.sub, max(y.sub, x.subr + y.subl));
	if (res.sub == x.sub) res.possub = x.possub;
	else if (res.sub == x.subr + y.subl) res.possub = r - x.subr + 1;
	else res.possub = y.possub;
	res.subl = x.subl + y.subl * (x.subl == x.sze);
	res.subr = y.subr + x.subr * (y.subr == y.sze);
	return res;
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node].sub = it[node].subl = it[node].subr = it[node].sze = 1;
		it[node].possub = l;
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1], (l + r) / 2);
}

void upd_lazy(int node, int l, int r) {
	if (lazy[node] != -1) {
		int newval = (lazy[node] ? 0 : r - l + 1);
		it[node].sub = it[node].subl = it[node].subr = newval;
		it[node].possub = l;
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = -1;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	upd_lazy(node, l, r);
	if (r < u || v < l) return ;
	if (u <= l && r <= v) {
		int newval = (val ? 0 : r - l + 1);
		it[node].sub = it[node].subl = it[node].subr = newval;
		it[node].possub = l;
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, u, v, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1], (l + r) / 2);
}

void query(int node, int l, int r, int val) {
	upd_lazy(node, l, r);
	if (l == r) {
		update(1, 1, n, l, r, 1);
		return ;
	}
	if (it[node * 2].sub >= val) {
		query(node * 2, l, (l + r) / 2, val);
		return ;
	}
	if (it[node * 2].subr + it[node * 2 + 1].subl >= val) {
		int pos = (l + r) / 2 - it[node * 2].subr + 1;
		update(1, 1, n, pos, pos + val - 1, 1);
		return ;
	}
	query(node * 2 + 1, (l + r) / 2 + 1, r, val);
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	build_tree(1, 1, n);
	memset(lazy, 255, sizeof(lazy));
	int res = 0;
	while (m --) {
		char c;
		cin >> c;
		if (c == 'A') {
			int x;
			cin >> x;
			if (it[1].sub >= x) query(1, 1, n, x);
			else res ++;
		}
		else {
			int l, r;
			cin >> l >> r;
			update(1, 1, n, l, r, 0);
		}
	}
	cout << res;
}
