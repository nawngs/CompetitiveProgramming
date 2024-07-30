//[UNFINISHED]
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	ll val;
	Node *l, *r;
	
	Node (ll x) : val(x), l(nullptr), r(nullptr) {}
	Node (Node *lv, Node *rv) {
		l = lv; r = rv;
		val = 0;
		if (l) val += l->val;
		if (r) val += r->val;
	}
	Node (Node *v) : val(v->val), l(v->l), r(v->r) {}
};

int a[NMAX + 3], cnt = 0, n, q;

Node *roots[NMAX + 3];

Node *build(int l = 1, int r = n) {
	if (l == r) return new Node(a[l]);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int l, int r, int pos, int val) {
	if (l == r) return new Node(val);
	int mid = (l + r) / 2;
	if (pos <= mid) return new Node(update(node->l, l, mid, pos, val), node->r);
	else return new Node(node->l, update(node->r, mid + 1, r, pos, val));
}

ll query(Node *node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return node->val;
	int mid = (l + r) / 2;
	return query(node->l, l, mid, u, v) + query(node->r, mid + 1, r, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roots[++ cnt] = build();
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int k, a, x; cin >> k >> a >> x;
			roots[k] = update(roots[k], 1, n, a, x);
		}
		if (type == 2) {
			int k, l, r; cin >> k >> l >> r;
			cout << query(roots[k], 1, n, l, r) << '\n';
		}
		if (type == 3) {
			int k; cin >> k;
			roots[++ cnt] = new Node(roots[k]);
		}
	}
}