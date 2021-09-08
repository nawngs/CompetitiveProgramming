#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, m, k, a[50004];

pair < ll, ll > it[400004];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node].fi = l;
		it[node].se = l;
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	if (a[it[node * 2].fi] > a[it[node * 2 + 1].fi]) it[node].fi = it[node * 2].fi;
	else it[node].fi = it[node * 2 + 1].fi;
	if (a[it[node * 2].se] < a[it[node * 2 + 1].se]) it[node].se = it[node * 2].se;
	else it[node].se = it[node * 2 + 1].se;
	//cout << l << " " << r << " " << it[node].fi << " " << it[node].se << '\n';
}

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		a[l] += val;
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	if (a[it[node * 2].fi] > a[it[node * 2 + 1].fi]) it[node].fi = it[node * 2].fi;
	else it[node].fi = it[node * 2 + 1].fi;
	if (a[it[node * 2].se] < a[it[node * 2 + 1].se]) it[node].se = it[node * 2].se;
	else it[node].se = it[node * 2 + 1].se;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> k >> m >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	ll ans = a[it[1].fi] - a[it[1].se];
	for (int i = 1; i <= m; i++) {
		if (a[it[1].fi] < k) break;
		update(1, 1, n, it[1].fi, -k);
		update(1, 1, n, it[1].se, k);
		ans = min(ans, a[it[1].fi] - a[it[1].se]);
	}
	cout << ans;
}