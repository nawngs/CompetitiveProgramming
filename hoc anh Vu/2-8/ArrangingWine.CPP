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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 4e6 + 5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll R, W, d, ans = 0, gt[nmax + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	ll up = gt[n];
	ll down = (gt[n - k] * gt[k]) % MOD;
	return (up * mu(down, MOD - 2)) % MOD;
}

 main() {
	fast;
	cin >> R >> W >> d;
	gt[0] = 1;
	for (ll i = 1; i <= nmax; i++) gt[i] = (gt[i - 1] * 1ll * i) % MOD;
	for (int i = 0; i <= min(R / (d + 1), W + 1); i++) {
		int temp = R - i * (d + 1);
		//cout << W << " " << temp << ' ' << Ckn(W, W + temp) << " " << Ckn(temp, W + temp) << '\n';
		if (i & 1) ans -= (Ckn(i, W + 1) * Ckn(W, W + temp)) % MOD;
		else ans += (Ckn(i, W + 1) * Ckn(W, W + temp)) % MOD;
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD;
}
