#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 1e9 + 7;
const int NMAX = 5e5;

int n, q, a[NMAX + 3];

map < int, int > f;

struct Node {
	int mn;
	Node *l, *r;
	Node(int v) : mn(v), l(nullptr), r(nullptr) {}
	Node (Node *lv, Node *rv) {
		l = lv, r = rv;
		mn = INF;
		if (l) mn = min(mn, l->mn);
		if (r) mn = min(mn, r->mn);
	}
	Node(Node *v) : mn(v->mn), l(v->l), r(v->r) {}
};

Node *roots[NMAX + 3];

Node *build(int l = 1, int r = n) {
	if (l == r) return new Node(INF);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int l, int r, int pos, int val) {
	if (l == r) return new Node(min(val, node->mn));
	int mid = (l + r) / 2;
	if (pos <= mid) return new Node(update(node->l, l, mid, pos, val), node->r);
	else return new Node(node->l, update(node->r, mid + 1, r, pos, val));
}

int query(Node *node, int l, int r, int u, int v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return node->mn;
	int mid = (l + r) / 2;
	return min(query(node->l, l, mid, u, v), query(node->r, mid + 1, r, u, v));
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
	roots[n] = build(); f[a[n]] = n;
	for (int i = n - 1; i >= 1; i--) {
		if (f.count(a[i])) {
			roots[i] = update(roots[i + 1], 1, n, f[a[i]], f[a[i]] - i);
		}
		else roots[i] = roots[i + 1];
		f[a[i]] = i;
	}
	while (q--) {
		int l, r; cin >> l >> r;
		int val = query(roots[l], 1, n, l, r);
		cout << (val == INF ? -1 : val) << '\n';
	}
}