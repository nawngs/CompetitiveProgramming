#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[200006], m, sum = 0;

ll bs2(ll val) {
	ll l = 1, r = n, mid, ans = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol(ll x, ll y) {
	ll res = bs2(x);
	ll ans = 0;
	if (res <= n) ans = max(1ll * 0, x - a[res]) + max(1ll * 0, y - (sum - a[res]));
	if (res > 1) ans = min(ans, max(1ll * 0, x - a[res - 1]) + max(1ll * 0, y - (sum - a[res - 1])));
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	cin >> m;
	while (m --) {
		ll x, y;
		cin >> x >> y;
		sol(x, y);
	}
}