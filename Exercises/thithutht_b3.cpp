#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plll pair < ll, pll > 

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, s[1005], dp[1005][1005], f[1005];

pll a[1005];


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	//roi_rac();
	sort(a + 1, a + n + 1, [](pll &x, pll &y) {
		return x.se < y.se;
	});
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[j].se < a[i].fi) {
				f[i] = j;
				break;
			}
		}
	}

	s[0] = 1;
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = s[f[j]];
			if (dp[i][j] != 0) ans = max(ans, 1ll * i);
		}
		s[0] = 0;
		for (int j = 1; j <= n; j++) {
			s[j] = s[j - 1] + dp[i][j];
		}
	}
	ll cnt = 0;
	for (int i = 1; i <= n; i++) cnt += dp[ans][i];
	cout << ans << " " << cnt;	
}
