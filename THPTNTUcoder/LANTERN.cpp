#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, m, a[100005];

bool check(ll x) {
	ll sum = 0;
	for (int i = 1; i <= m; i++) sum += (a[i] + x - 1) / x;
	return sum <= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	ll l = 1, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}