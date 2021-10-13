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

ll n, a[500005], cnt[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	ll r = 0;
	ll ans = 0;
	FOR(i, 1, n) {
		while (r < n) {
			if (cnt[a[r + 1]] >= 2) break;
			r ++;
			cnt[a[r]] ++;
		}
		ans += r - i + 1;
		cnt[a[i]] --;
	}
	cout << ans;
}
