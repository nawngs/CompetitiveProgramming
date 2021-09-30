#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

struct Data {
	ll w, v, a;
} a[105];

ll n, w, demf = 0;;

pll f[1505];

int main() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w >> a[i].v >> a[i].a;
		for (int j = 1; j <= a[i].a; j *= 2) {
			f[++ demf] = {a[i].w * j, a[i].v * j};
			a[i].a -= j;
		}
		//cout << a[i].a << '\n';
		if (a[i].a != 0) f[++ demf] = {a[i].w * a[i].a, a[i].v * a[i].a};
	}
	ll ans = 0;
	//cout << demf << '\n';
	ll dp[demf + 5][w + 5];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= demf; i++) {
		for (int j = 0; j <= w; j++) {
			if (j >= f[i].fi) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - f[i].fi] + f[i].se);
			else dp[i][j] = dp[i - 1][j];
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}