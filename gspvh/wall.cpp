//#include "wall.h" /// DO NOT CHANGE THIS LINE

#include <bits/stdc++.h>

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

/// You can declare global variables here if necessary.
/// But you are NOT allowed to write `main` function.

/// You have to implement the below functions:

const int NMAX = 1234321;
const int INF = 1E9 + 7;

int n, a[NMAX + 3];

pii it[6 * NMAX + 3];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = {a[l], a[l]};
		return ;
	}
	it[node] = {-1, INF};
	build(lnode); build(rnode);
}

void merge(pii &x, const pii &y) {
	if (x.se < y.fi) {
		x = {y.fi, y.fi};
		return ;
	}
	if (x.fi > y.se) {
		x = {y.se, y.se};
		return ;
	}
	x = mp(max(x.fi, y.fi), min(x.se, y.se));
}

void update(int node, int l, int r) {
	if (it[node] != mp(-1, INF)) {
		if (l != r) {
			merge(it[node * 2], it[node]);
			merge(it[node * 2 + 1], it[node]);
			it[node] = {-1, INF};
		}
	}
}

void update(int node, int l, int r, int u, int v, pii val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		merge(it[node], val);
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
} 

void prepare(int subtask, const vector<int> &height) {
	n = height.size();
	for (int i = 1; i <= n; i++) a[i] = height[i - 1];
	build(1, 1, n);
}

void build_up(int l, int r, int t) {
	l ++; r ++;
	update(1, 1, n, l, r, {t, INF});
}

void take_down(int l, int r, int t) {
	l ++; r ++;
	update(1, 1, n, l, r, {-1, t});
}

int get_height(int i) {
	i ++;
	int node = 1, l = 1, r = n;
	pii temp = {-1, -1};
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (l == r) break;
		if (i <= mid) {
			node *= 2;
			r = mid;
		}
		else {
			node = node * 2 + 1;
			l = mid + 1;
		}
	}
	temp = it[node];
	while (node >= 1) {
		merge(temp, it[node]);
		node /= 2;
	}
	assert(temp.fi == temp.se);
	return temp.fi;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector < int > vec;
	vec.resize(n, 0);
	for (auto &x : vec) x = 0;
	prepare(1, vec);
	while (q--) {
		int type, l, r, t; cin >> type >> l >> r >> t;
		if (type == 1) build_up(l, r, t);
		else take_down(l, r, t);
	}
	for (int i = 0; i < n; i++) cout << get_height(i) << '\n';
}