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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 1e5;
const int NMAX = 5E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Node {
	int s, l, r;
	Node() {
		s = l = r = 0;
	}
	Node(int x) {
		s = x; l = r = 0;
	}
} it[NMAX + 3];

int n, q, k, ql[N + 3], qr[N + 3], a[N + 3], root[N + 3], nnode = 0, pos[N + 3];

int build(int l, int r) {
	if (l == r) {
		it[++nnode] = Node();
		return nnode;
	}
	int mid = (l + r) / 2, cur = ++ nnode;
	it[cur].l = build(l, mid); it[cur].r = build(mid + 1, r);
	return cur;
}

int update(int node, int l, int r, int pos) {
	if (l == r) {
		it[++nnode] = Node(1);
		return nnode;
	}
	int mid = (l + r) / 2, cur = ++nnode;
	it[cur] = it[node];
	if (pos <= mid) it[cur].l = update(it[cur].l, l, mid, pos);
	else it[cur].r = update(it[cur].r, mid + 1, r, pos);
	it[cur].s = it[it[cur].l].s + it[it[cur].r].s;
	return cur;
}

int walk(int node, int l, int r, int x) {
	if (l == r) return l;
	int lid = it[node].l, rid = it[node].r;
	if (it[lid].s >= x) return walk(lid, l, (l + r) / 2, x);
	else {
		x -= it[lid].s;
		return walk(rid, (l + r) / 2 + 1, r, x);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> ql[i] >> qr[i];
	root[0] = build(1, n);
	for (int i = 1; i <= n; i++) 
		root[i] = update(root[i - 1], 1, n, a[i]), pos[a[i]] = i;
	for (int i = q; i >= 1; i--) {
		if (k < ql[i] || qr[i] < k) continue;
		int v = k - ql[i] + 1;
		k = pos[walk(root[qr[i] - ql[i] + 1], 1, n, v)];
		k = k + ql[i] - 1;
	}
	cout << k;
}