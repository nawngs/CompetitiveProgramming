#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

int n, m, a[200005], it[1200005];

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u || l > r) return -1e9;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void sol(int x) {
	int l = 1, r = n, mid , ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (query(1, 1, n, 1, mid) >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (ans != 0) {
		a[ans] -= x;
		update(1, 1, n, ans, a[ans]);
	}
	cout << ans << ' ';
}

int main() {
		ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		sol(x);
	}
}