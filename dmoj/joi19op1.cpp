#include <bits/stdc++.h>

#define name "triple"
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
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[NMAX + 3], res[NMAX + 3];

vector < int > upd[NMAX + 3];

vector < pii > qr[NMAX + 3];

struct Node {
	ll vl, sub;
	Node() {
		vl = 0, sub = 0;
	}
} it[6 * NMAX + 3];

ll lazy[6 * NMAX + 3];

Node merge(const Node &x, const Node &y) {
	Node res;
	res.vl = max(x.vl, y.vl);
	res.sub = max(x.sub, y.sub);
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].vl = a[l];
		it[node].sub = a[l];
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].sub = max(it[node].sub, it[node].vl + lazy[node]);
		if (l != r) {
			lazy[node * 2] = max(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return Node();
	if (u <= l && r <= v) return it[node];
	return merge(query(lnode, u, v), query(rnode, u, v));
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	stack < int > st; st.push(0); a[0] = LINF; 	
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] < a[i]) st.pop();
		upd[st.top()].pb(i);
		st.push(i);
	}
	while (st.size() > 1) st.pop();
	for (int i = n; i >= 1; i--) {
		while (a[st.top()] < a[i]) st.pop();
		if (st.top() != 0) upd[i].pb(st.top());
		st.push(i);
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		qr[l].pb({r, i});
	}
	for (int i = n; i >= 1; i--) {
		for (auto x : upd[i]) update(1, 1, n, 2 * x - i, n, a[i] + a[x]);
		for (auto x : qr[i]) res[x.se] = query(1, 1, n, i, x.fi).sub;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}