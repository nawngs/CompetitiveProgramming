#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, s, x, a[1005], cnt[1005];

ll calc(ll x, ll val) {
	if (x == 0) return 0;
	if (x % val == 0) return 1 + calc(x / val, val);
	else return (x % val) + calc(x - (x % val), val);
} 

ll bs(ll val, ll r) {
	ll l = 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (cnt[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("TwoPress.INP", "r", stdin);
	freopen("TwoPress.OUT", "w", stdout);
	//cout << calc(10, 1) << '\n';
	cin >> n >> s >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt[i] = x;
		else cnt[i] = calc(x, a[i]);
	}
	ll res = 0;
	sort(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll tam = bs(s - cnt[i] - cnt[j], i - 1);
			if (tam == -1) break;
			res += tam;
			//cout << i << " " << j << " " << tam << '\n';
		}
	}
	cout << res << '\n';
}