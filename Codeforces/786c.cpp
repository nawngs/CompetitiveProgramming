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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3], lst[N + 3], nnode = 0, root[N + 3];

struct Node {
	int s, l, r;
	Node() {
		s = l = r = 0;
	}
} it[N * 160 + 3];

int build(int node, int l, int r) {
	if (l == r) {
		it[++ nnode] = Node();
		return nnode;
	}
	int id = ++ nnode;
	it[id].l = build(lnode); it[id].r = build(rnode);
	return id;
}

int update(int node, int l, int r, int pos, int val) {
	if (l == r) {
		it[++nnode].s = val;
		return nnode;
	}
	int mid = (l + r) / 2, id = ++ nnode;
	it[id] = it[node];
	if (pos <= mid) it[id].l = update(it[node].l, l, mid, pos, val);
	else it[id].r = update(it[node].r, mid + 1, r, pos, val);
	it[id].s = it[it[id].l].s + it[it[id].r].s;
	// cout << id << " " << l << " " << r << " " << it[id].s << '\n';
	return id;
}

int walk(int node, int l, int r, int x) {
	if (l == r) return l;
	int lid = it[node].l, rid = it[node].r;
	if (it[lid].s > x) return walk(lid, l, (l + r) / 2, x);
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
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	root[n + 1] = build(1, 1, n + 1);
	for (int i = n; i >= 1; i--) {
		root[i] = update(root[i + 1], 1, n + 1, i, 1);
		if (lst[a[i]] > i) root[i] = update(root[i], 1, n + 1, lst[a[i]], 0);
		lst[a[i]] = i;
	}
	// cout << walk(root[1], 1, n + 1, 1) << '\n';
	for (int i = 1; i <= n; i++) {
		int cur = 1, res = 0;
		while (cur <= n && ++res) 
			cur = walk(root[cur], 1, n + 1, i);
		cout << res << " ";
	}
}