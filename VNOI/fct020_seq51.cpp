#include <bits/stdc++.h>

using namespace std;

int n, a[100005], it[800005], lazy[800005];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, int val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l < r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (r < u || v < l || l > r)return ;
	if (u <= l && r <= v) {
		it[node] += val;
		if (l < r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (r < u || v < l || l > r)return 1e9;
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l < r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));

}

bool check(int x) {
	memset(lazy, 0, sizeof(lazy));
	build_tree(1, 1, n);
	for (int i = n; i >= 1; i --) {
		if (i > n - x + 1) update(1 , 1, n, i, n, -1);
		else {
			update(1, 1, n, i, i + x - 1, -1);
			int tam = query(1, 1, n, i, i + x - 1);
			//if (x == 4) cout << tam << '\n';
			if (tam >= 0) return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 0, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}