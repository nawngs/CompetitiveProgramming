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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	ll total, sum, suma;
	Node() {
		total = sum = suma = 0;
	}
	Node operator + (const Node &oth) {
		Node res;
		res.total = total + oth.total;
		res.sum = sum + oth.sum;
		res.suma = suma + oth.suma;
		return res;
	}
} it[6 * NMAX + 3];

ll n, a[NMAX + 3], m, lazy[6 * NMAX + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node].total = a[l] * l;
		it[node].sum = a[l];
		it[node].suma = l;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].total += lazy[node] * it[node].suma;
		it[node].sum += lazy[node] * (r - l + 1);
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll x) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = x;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, x); update(rnode, u, v, x);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

Node query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	if (v <= mid) return query(lnode, u, v);
	if (u > mid) return query(rnode, u, v);
	return query(lnode, u, v) + query(rnode, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			ll l, r, x; cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
		else {
			int l, r; cin >> l >> r;
			Node res = query(1, 1, n, l, r);
			cout << res.total - res.sum * (l - 1) << '\n';
		}
	}
}