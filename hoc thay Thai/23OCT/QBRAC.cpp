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
const int N = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q;

string s;

struct Node {
	int total[2], mx[2];
	Node() {
		for (int i = 0; i < 2; i++) 
			total[i] = mx[i] = 0;
	}
} it[6 * N + 3];

int lazy[6 * N + 3];

Node merge(const Node &x, const Node &y) {
	Node res;
	for (int i = 0; i < 2; i++) {
		res.total[i] = x.total[i] + y.total[i];
		res.mx[i] = max(x.mx[i], x.total[i] + y.mx[i]);
	}
	return res;
}

void build(int node, int l, int r) {
	lazy[node] = -1;
	if (l == r) {
		it[node].total[0] = it[node].mx[0] = (s[l] == '(' ? 1 : -1);
		it[node].total[1] = it[node].mx[1] = (s[l] == ')' ? 1 : -1);
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

int merge(const int &x, const int &y) {
	if (x == -1) return y;
	if (y <= 1) return y;
	return x ^ 1;
}

void update(int node, int l, int r) {
	if (lazy[node] != -1) {
		if (lazy[node] == 0) {
			it[node].total[0] = it[node].mx[0] = r - l + 1;
			it[node].total[1] = it[node].mx[1] = -(r - l + 1);
		}
		if (lazy[node] == 1) {
			it[node].total[1] = it[node].mx[1] = r - l + 1;
			it[node].total[0] = it[node].mx[0] = -(r - l + 1);
		}
		if (lazy[node] == 2) {
			swap(it[node].total[0], it[node].total[1]);
			swap(it[node].mx[0], it[node].mx[1]);
		}
		if (l != r) {
			lazy[node * 2] = merge(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = merge(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = -1;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return;
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
	if (u <= l && r <= v) return it[node];
	if (v <= (l + r) / 2) return query(lnode, u, v);
	if (u > (l + r) / 2) return query(rnode, u, v);
	return merge(query(lnode, u, v), query(rnode, u, v));
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q >> s; s = ' ' + s;
	build(1, 1, n);
	while (q--) {
		int l, r; char c; cin >> l >> r >> c;
		if (c == '?') {
			Node temp = query(1, 1, n, l, r);
			if (temp.mx[1] > 0 || temp.total[0] != 0) cout << "no" << '\n';
			else cout << "yes" << '\n';
		}
		if (c == '(') update(1, 1, n, l, r, 0);
		if (c == ')') update(1, 1, n, l, r, 1);
		if (c == '-') update(1, 1, n, l, r, 2);
	}
}