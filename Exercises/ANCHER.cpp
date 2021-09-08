#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, r, k, a[500005], b[500005], s[500005], f[500005];

bool check(ll x) {
	ll tam = k;
	for (int i = 0; i <= n; i++) f[i] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] += f[i - 1];
		ll temp = b[i] + f[i];
		if (temp < x) {
			if (x - temp > tam) return false;
			int posl = i + 1, posr = min(1ll * (i + 2 * r), n);
			f[posl] += x - temp;
			f[posr + 1] -= (x - temp);
			tam -= (x - temp);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("ANCHER.inp", "r", stdin);
	freopen("ANCHER.out", "w", stdout);
	cin >> n >> r >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i]; 
	}
	for (int i = 1; i <= n; i++) {
		int posr = min(n, 1ll * (i + r));
		int posl = max(1ll * 1, (i - r));
		b[i] = s[posr] - s[posl - 1];	
	}
	ll l = 0, r = 2e18, ans = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}