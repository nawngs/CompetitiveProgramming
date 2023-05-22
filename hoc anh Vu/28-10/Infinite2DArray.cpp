#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

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
const ll nmax = 2e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}
ll f[nmax + 3], frac[nmax + 3], a, b, res = 0;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

int main() {
	fast;
	f[0] = 0, f[1] = 1;
	frac[0] = frac[1] = 1;
	for (int i = 2; i <= nmax; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
		frac[i] = (frac[i - 1] * i) % MOD;
	}
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		res = (res + f[i] * C(a - i, a - i + b - 1)) % MOD;
	}
	for (int i = 1; i <= b; i++)
		res = (res + f[i] * C(b - i, a + b - i - 1)) % MOD;
	cout << res;
	
}
