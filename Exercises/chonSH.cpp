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

ll n, a[500005], s[500005], sum;

int main() {
	fastflow;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	cin >> sum;
	ll l = 1, r = 1;
	ll ans = 1;
	while (1) {
		if (l > n || r > n) break;
		if (s[r] - s[l - 1] <= sum) {
			ans = max(ans, r - l + 1);
			r ++;
		}
		else l ++;
	}
	cout << ans;
}
