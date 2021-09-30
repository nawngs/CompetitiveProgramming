#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

ll n, a[200005], s[200005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + a[i] * a[i]) % MOD;
		ans = (ans + a[i] * s[i - 1]) % MOD;
		s[i] = (s[i - 1] * 2 + a[i]) % MOD;
		//cout << i << " " << ans << '\n';
	}
	cout << ans;
}
