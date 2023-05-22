#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "PRODUCT";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 123456789;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a[100003];

ll tich (ll x, ll y) {
	return ((x * y) % MOD + MOD) % MOD;
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 1;
	if (k % 2 == 0) {
		ll l = 1;
		ll r = n;
		ans = 1;
		while (k > 0) {
			if (a[l] * a[l + 1] > a[r] * a[r - 1]) {
				ans = (ans * tich(a[l], a[l + 1])) % MOD;
				l += 2;
			}
			else {
				ans = (ans * tich(a[r], a[r - 1])) % MOD;
				r -= 2;
			}
			k -= 2;
		}
	}
		else {
			if (a[n] <= 0) {
				ans = 1;
				for (int i = n; i >= n - k + 1; i--) ans = tich(ans, a[i]);
			}
			else {
				ans = a[n] % MOD;
				ll l = 1;
				ll r = n - 1;
				k -= 1;
				while (k > 0) {
					if (a[l] * a[l + 1] > a[r] * a[r - 1]) {
						ans = (ans * tich(a[l], a[l + 1])) % MOD;
						l += 2;
					}
					else {
						ans = (ans * tich(a[r], a[r - 1])) % MOD;
						r -= 2;
					}
					k -= 2;
				}
			}
		}
		cout << ans << '\n';

}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
