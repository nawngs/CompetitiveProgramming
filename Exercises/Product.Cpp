#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 123456789; 

int t;

long long n, a[100005], k, duong[100005], am[100005];

void nhan (long long&x, long long y) {
	x = (((x % MOD) * (y % MOD)) % MOD + MOD) % MOD;
}

void sol() {
	cin >> n >> k;
	ll cnt_am = 0, cnt_duong = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		duong[i] = 0;
		am[i] = 0;
	}
	
	sort(a + 1, a + n + 1);

	if ((a[n] < 0 && k % 2 == 0) || (n == k)) {
		long long ans = 1;
		for (int i = 1; i <= k; i++) nhan(ans, a[i]);
		cout << ans << '\n';
		return ;
	}

	if ((a[n] <= 0 && k % 2 == 1) || (a[1] >= 0)) {
		long long ans = 1;
		for (int i = 1; i <= k; i++) nhan(ans, a[n - i + 1]);
		cout << ans << '\n';
		return ;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] < 0) am[++ cnt_am] = a[i];
		if (a[i] > 0) duong[++ cnt_duong] = a[i];
	}

	if (cnt_duong + cnt_am < k) {
		cout << 0 << '\n';
		return ;
	}

	sort(am + 1, am + cnt_am + 1);
	sort(duong + 1, duong + cnt_duong + 1, greater < int >());

	if (k % 2 == 0) {
		ll pos1, pos2;
		if (k <= cnt_duong) {
			pos1 = k;
			pos2 = k - pos1;
		}
		else {
			pos1 = cnt_duong - (cnt_duong % 2);
			pos2 = k - pos1;
		}
		while(1) {
			if (pos1 < 2 || pos2 > cnt_am - 2) break;
			if (am[pos2 + 1] * am[pos2 + 2] < duong[pos1] * duong[pos1 - 1]) break;
			pos2 += 2;
			pos1 -= 2;
		}
		ll ans = 1;
		//cout << pos1 << " " << pos2 << '\n';
		for (int i = 1; i <= pos1; i++) nhan(ans, duong[i]);
		for (int i = 1; i <= pos2; i++) nhan(ans, am[i]);
		cout << ans << '\n';
		return ;
	}

	if (k % 2 == 1) {
		ll pos1, pos2;
		if (k <= cnt_duong) {
			pos1 = k;
			pos2 = k - pos1;
		}
		else {
			pos1 = cnt_duong - (cnt_duong % 2 == 0);
			pos2 = k - pos1;
		}
		while(1) {
			if (pos1 < 2 || pos2 > cnt_am - 2) break;
			if (am[pos2 + 1] * am[pos2 + 2] < duong[pos1] * duong[pos1 - 1]) break;
			pos2 += 2;
			pos1 -= 2;
		}
		ll ans = 1;
		for (int i = 1; i <= pos1; i++) nhan(ans, duong[i]);
		for (int i = 1; i <= pos2; i++) nhan(ans, am[i]);
		cout << ans << '\n';
		return ;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("product.Inp", "r", stdin);
	freopen("product.Out", "w", stdout);
	cin >> t;
	while (t --) sol();
}