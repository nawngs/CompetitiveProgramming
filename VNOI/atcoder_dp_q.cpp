#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, it[1200005];

pll a[200005], f[200005];

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u || l > r) return 0;
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		f[i].fi = a[i].fi;
		f[i].se = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i].se;
	sort(f + 1, f + n + 1);
	f[0].fi = -1e18;
	ll dem = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i].fi != f[i - 1].fi) dem ++;
		a[f[i].se].fi = dem;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll tam = query(1, 0, n, 0, a[i].fi - 1);
		//cout << a[i].fi << " " << a[i].se << " " << tam << '\n';
		tam += a[i].se;
		ans = max(ans, tam);
		update(1, 0, n, a[i].fi, tam);
	}
	cout << ans;
}
