#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a, b, k, lbs, rbs;

ll bs1(ll x, ll l, ll r) {
	ll  mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (mid * mid >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

ll bs2 (ll x, ll l, ll r) {
	ll mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (mid * mid <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main() {
	cin >> a >> b >> k;
	lbs = bs1(a, 1, 1e9);
	rbs = bs2(b, 1, 1e9);
	ll ans = 0;
	for (ll i = 1; i <= 1e6; i++) {
		ll tam = i * i * i;
		if (tam < a) continue;
		if (tam > b) break;
		//cout << lbs << " " << rbs << '\n';
		ll l = bs1(max(a, tam - k), lbs, rbs);
		ll r = bs2(min(b, tam + k), lbs, rbs);
		if (l == -1 || r == -1) continue;
		ans += (r - l + 1); 
		//cout << i << " " << l << " " << r << '\n';
	}
	cout << ans;
}
