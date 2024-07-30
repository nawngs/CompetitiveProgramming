#include <bits/stdc++.h>

#define name ""
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
const int N = 3e5;

struct Node {
	int sub, ll, lr, ml, mr, sz;
	long long vl, vr;
	// ll a[i] > a[i + 1]
	// lr a[i] < a[i + 1]
	Node(int x = -1) {
		sub = ll = lr = ml = mr = sz = 1;
		vl = vr = x;
	}
	Node operator + (const Node &oth) const {
		Node res; res.vl = vl; res.vr = oth.vr; res.sz = sz + oth.sz;
		res.sub = max(sub, oth.sub);
		if (vr > oth.vl) res.sub = max(res.sub, mr + oth.ll); // k ben trai
		if (vr < oth.vl) res.sub = max(res.sub, oth.ml + lr); // k ben phai
		res.ll = ll;
		if (ll == sz && vr > oth.vl) res.ll += oth.ll; 
		res.lr = oth.lr;
		if (oth.lr == oth.sz && vr < oth.vl) res.lr += lr;
		res.ml = ml;
		if (ml == sz && vr > oth.vl) res.ml += oth.ll;
		if (lr == sz && vr < oth.vl) res.ml = oth.ml + sz;
		res.mr = oth.mr;
		if (oth.mr == oth.sz && vr < oth.vl) res.mr += lr;
		if (oth.ll == oth.sz && vr > oth.vl) res.mr = mr + oth.sz;
		return res;
	}
} it[8 * N + 3];

int n, a[N + 3];

long long lazy[8 * N + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = Node(a[l]);
		return ;
	}
	build(lnode); build(rnode);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].vl += lazy[node];
		it[node].vr += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
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
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int l, r, d; cin >> l >> r >> d;
		update(1, 1, n, l, r, d);
		cout << it[1].sub << '\n';
	}
}