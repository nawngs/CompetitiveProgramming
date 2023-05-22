#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll l, r, cur[nmax + 3], res[nmax + 3];

signed main() {
	fast;
	//fast;
	cin >> l >> r;
	if (l <= -1 && -1 <= r) {
		cout << -1 << '\n';
		return 0;
	}
	l ++; r++;
	for (ll i = l; i <= r; i++) {
		cur[i - l] = i;
		res[i - l] = 1;
	}
	ll high = max(abs(r), abs(l));
	for (ll i = 2; i * i <= high; i++) {
		for (ll j = l / i * i + i * (l % i > 0); j <= r; j+=i) {
			ll dem = 0;
			while (cur[j - l] % i == 0) {
				dem ++;
				cur[j - l] /= i;
			}
			res[j - l] = res[j - l] * (dem + 1);
			//cout << i << " " << j << " " << cur[j - l] << " " << res[j - l] << '\n';
		}
	}
	ll ans = 0;
	for (ll i = l; i <= r; i++) {
		if (cur[i - l] != 1 && cur[i - l] != -1) res[i - l] *= 2;
		ans += res[i - l];
		ll temp = sqrtl(i);
		if (i > 0 && temp * temp == i) ans ++;
	}
	cout << ans;
}
