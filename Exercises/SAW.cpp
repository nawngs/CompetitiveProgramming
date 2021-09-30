#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, k, a[100005], s[100005];

ll bs(ll x) {
	ll l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] > x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}


ll calc(ll x) {
	ll tam = bs(x);
	if (tam == -1) return 0;
	return s[tam] - (n - tam + 1) * x;
}

void sol(ll x) {
	ll l = 0, r = 1e9, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (calc(mid) >= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("SAW.INP", "r", stdin);
	//freopen("SAW.OUT", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) s[i] = s[i + 1] + a[i];
	while (k --) {
		ll x;
		cin >> x;
		sol(x);
	}
}