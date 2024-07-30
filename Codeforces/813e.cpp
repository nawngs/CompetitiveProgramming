//[FINISHED]
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
const int N = 5e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	int val, l, r;
	Node() {
		val = l = r = 0;
	}
	Node(int x) {
		val = x;
	}
};

int n, k, a[NMAX + 3];

queue < int > st[NMAX + 3];

int roots[NMAX + 3], nnode = 0;

Node it[N + 3];

void calc(int id) {
	int x = it[id].l, y = it[id].r;
	it[id].val = (x == 0 ? 0 : it[x].val) + (y == 0 ? 0 : it[y].val);
}

int update(int node, int l, int r, int pos, int val) {
	if (l == r) {
		it[++ nnode] = Node(it[node].val + val);
		return nnode;
	}
	int mid = (l + r) / 2, cur = ++nnode;
	if (pos <= mid) {
		it[cur].l = update(it[node].l, l, mid, pos, val);
		it[cur].r = it[node].r;
	}
	else {
		it[cur].l = it[node].l;
		it[cur].r = update(it[node].r, mid + 1, r, pos, val);
	}
	calc(cur);
	return cur;
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].val;
	int mid = (l + r) / 2;
	return query(it[node].l, l, mid, u, v) + query(it[node].r, mid + 1, r, u, v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		roots[i] = update(roots[i + 1], 1, n, i, 1);
		st[a[i]].push(i);
		if (SZE(st[a[i]]) > k) {
			roots[i] = update(roots[i], 1, n, st[a[i]].front(), -1);
			st[a[i]].pop();
		}
		//for (int j = i; j <= n; j++) cout << i << " " << j << " " << query(roots[i], 1, n, i, j) << '\n';
	}
	int q; cin >> q;
	int ans = 0;
	while (q--) {
		int l, r; cin >> l >> r;
		l = (l + ans) % n + 1;
		r = (r + ans) % n + 1;
		if (l > r) swap(l, r);
		ans = query(roots[l], 1, n, l, r);
		cout << ans << '\n';
	}
}