#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, k, a[100005];

ll calc(ll l, ll r) {
	return (r + l) * (r - l + 1) / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll dem = 1;
	ll ans = 0;
	ROF(i, n, 1) {
		//cout << k << '\n';
		if ((a[i] - a[i - 1]) * dem < k) {
			k -= (a[i] - a[i - 1]) * dem;
			ans += dem * calc(a[i - 1] + 1, a[i]);
			dem ++;
			continue;
		}
		else {
			ll tam = k / dem;
			ll temp = k % dem;
			if (tam != 0) ans += dem * calc(a[i] - tam + 1, a[i]);
			ans += temp * (a[i] - tam);
			break;
		}
	}
	cout << ans;
}
