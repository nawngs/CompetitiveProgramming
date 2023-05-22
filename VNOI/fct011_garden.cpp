#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, l;

pll a[100005];

bool check(ll x) {
	ll res = 0;	
	FOR(i, 1, n) {
		ll tam = x - a[i].fi;
		if (tam < 0) continue;
		tam += a[i].se - 1;
		res += 1ll * (tam / a[i].se);
	}
	return (res <= l);
}

int main() {
	fastflow;
	cin >> n >> l;
	FOR(i, 1, n) cin >> a[i].fi >> a[i].se;
	ll l = 1, r = 1e14, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}
