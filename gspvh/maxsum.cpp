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

const string NAME = "maxsum";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e15;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Input {
	int l, r, index;
	ll val;
	bool IsQuery;
} a[900003];

struct Node {
	int posl, posr;
	int l, r;
	ll subNode, subl, subr;
	pii posSub;
};

int n, q;

Node it[1600005];

Node res[500003];

Node merge(Node x, Node y) {
	Node res;
	ll sub_merge = x.subr + y.subl;
	res.subNode = max(-INF, max(sub_merge, max(x.subNode, y.subNode)));
	if (res.subNode == x.subNode) res.posSub = x.posSub;
	else if (res.subNode == y.subNode) res.posSub = y.posSub;
	else res.posSub = {x.posl, y.posr};
	//##############################################################################
	if (x.posl == x.r && y.subl > 0) {
		res.posl = y.posl;
		res.subl = max(-INF, x.subl + y.subl);
	}
	else {
		res.posl = x.posl;
		res.subl = x.subl;
	}
	//##############################################################################
	if (y.posr == y.l && x.subr > 0) {
		res.posr = x.posr;
		res.subr = max(-INF, x.subr + y.subr);
	}
	else {
		res.posr = y.posr;
		res.subr = y.subr;
	}
	res.l = x.l;
	res.r = y.r;
	return res;
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node].l = it[node].r = it[node].posl = it[node].posr = l;
		it[node].subNode = it[node].subl = it[node].subr = -INF;
		it[node].posSub = {l, r};
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].subNode = it[node].subl = it[node].subr = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	Node res;
	if (v < l || r < u) {
		res.l = res.r = -1;
		return res;
	}
	if (u <= l && r <= v) return it[node];
	Node lnode = query(node * 2, l, (l + r) / 2, u, v);
	Node rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	if (lnode.l == -1) return rnode;
	else if (rnode.r == -1) return lnode;
	else return merge(lnode, rnode);
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].l = a[i].r = a[i].index = i;
		a[i].IsQuery = false;
	}
	for (int i = 1; i <= q; i++) {
		cin >> a[i].l >> a[i].r >> a[i].val;
		a[i].index = i;
		a[i].IsQuery = 1;
	}
	sort(a + 1, a + n + q + 1, [](Input &x, Input &y) {
		return (x.val > y.val) || (x.val == y.val && x.IsQuery == 0);
	});
	build_tree(1, 1, n);
	for (int i = 1; i <= n + q; i++) {
		if (!a[i].IsQuery) update(1, 1, n, a[i].l, a[i].val);
		else res[a[i].index] = query(1, 1, n, a[i].l, a[i].r);
	}
	for (int i = 1; i <= q; i++) {
		if (res[i].subNode == -INF) cout << 0 << '\n';
		else cout << res[i].posSub.fi << " " << res[i].posSub.se << '\n';
	} 
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
