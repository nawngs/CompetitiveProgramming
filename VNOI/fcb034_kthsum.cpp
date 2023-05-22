#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k, a[100005], it[800005], f[100005], b[100005];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	if (a[it[node * 2]] < a[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	if (a[it[node * 2]] < a[it[node * 2 + 1]]) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = 1;
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	b[n + 1] = 1e18;
	for (int i = 1; i <= n; i++) a[i] = a[i] + b[f[i]];
	build_tree(1, 1, n);
	for (int i = 1; i <= k; i++) {
		int pos = it[1];
		cout << a[pos] << ' ';
		a[pos] = a[pos] - b[f[pos]] + b[f[pos] + 1];
		f[pos] ++;
		update(1, 1, n, pos, a[pos]);
	}
}
