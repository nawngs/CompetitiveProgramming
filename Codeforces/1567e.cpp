#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Data {
	ll sub, l, r;
} it[1600005];

ll n, q, a[200005];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node].sub = 1;
		it[node].l = 1;
		it[node].r = 1;
		//cout << l << " " << r << " " << it[node].sub << " " << it[node].l << " " << it[node].r << '\n';
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node].sub = it[node * 2].sub + it[node * 2 + 1].sub;
	if (a[mid + 1] >= a[mid]) it[node].sub += it[node * 2].r * it[node * 2 + 1].l;
	it[node].r = it[node * 2 + 1].r;
	if (it[node * 2 + 1].r == r - mid && a[mid + 1] >= a[mid]) it[node].r += it[node * 2].r;
	it[node].l = it[node * 2].l;
	if (it[node * 2].l == mid - l + 1 && a[mid + 1] >= a[mid]) it[node].l += it[node * 2 + 1].l;
	//cout << l << " " << r << " " << it[node].sub << " " << it[node].l << " " << it[node].r << '\n';
}

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		//a[l] = val;
		it[node].sub = 1;
		it[node].l = 1;
		it[node].r = 1;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node].sub = it[node * 2].sub + it[node * 2 + 1].sub;
	if (a[mid + 1] >= a[mid]) it[node].sub += it[node * 2].r * it[node * 2 + 1].l;
	it[node].r = it[node * 2 + 1].r;
	if (it[node * 2 + 1].r == r - mid && a[mid + 1] >= a[mid]) it[node].r += it[node * 2].r;
	it[node].l = it[node * 2].l;
	if (it[node * 2].l == mid - l + 1 && a[mid + 1] >= a[mid]) it[node].l += it[node * 2 + 1].l;
}

Data query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u || l > r) {
		Data ans;
		ans.sub = 0;
		ans.l = 0;
		ans.r = 0;
		return ans;
	}
	if (u <= l && r <= v) return it[node];

	int mid = (l + r) / 2;
	Data lnode = query(node * 2, l, mid, u, v);
	Data rnode = query(node * 2 + 1, mid +1 , r, u, v);
	Data ans;
	ans.sub = 0;
	ans.sub = lnode.sub + rnode.sub;
	if (a[mid + 1] >= a[mid]) ans.sub += lnode.r * rnode.l;
	ans.r = rnode.r;
	if (rnode.r == r - mid && a[mid + 1] >= a[mid]) ans.r += lnode.r;
	ans.l = lnode.l;
	if (lnode.l == mid - l + 1 && a[mid + 1] >= a[mid]) ans.l += rnode.l;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	while (q --) {
		int u, v, c;
		cin >> u >> v >> c;
		if (u == 2) {
			Data tam = query(1, 1, n, v, c);
			cout << tam.sub << '\n';
		}
		else {
			a[v] = c;
			update(1, 1, n, v, c);
		}
	}
}