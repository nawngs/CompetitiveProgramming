#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, a[200005], it[1200006];

pll p[200005];

void update(ll node, ll l, ll r, ll pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] ++;
		return;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos);
	update(node * 2 + 1, mid + 1, r, pos);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u || l > r) return 0;
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void roi_rac() {
	for (int i = 1; i <= n; i++) {
		p[i].fi = a[i];
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	ll dem = 0;
	p[0].fi = INF;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= 6 * n; i++) it[i] = 0;
	//cout << "YES" << '\n';
	roi_rac();
	//cout << "YES" << '\n';
	deque < ll > dq;
	dq.push_back(a[1]);
	update(1, 0, n, a[1]);
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		ll behon = query(1, 0, n, 0, a[i] - 1), lonhon = query(1, 0, n, a[i] + 1, n);
		//cout << a[i] << " " << behon << " " << lonhon << '\n';
		if (behon < lonhon) dq.push_back(a[i]);
		else dq.push_front(a[i]);
		update(1, 0, n, a[i]);
		ans += min(behon, lonhon);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
