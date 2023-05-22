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

const string NAME = "photo";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll nam, nu, co;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	ll up = 1, down = 1;
	for (int i = 1; i <= n; i++) up = (up * i) % MOD;
	for (int i = 1; i <= k; i++) down = (down * i) % MOD;
	for (int i = 1; i <= n - k; i++) down = (down * i) % MOD;
	return (up * mu(down, MOD - 2)) % MOD;

}

int main() {
	fast;
	fre();
	cin >> nu >> nam >> co;
	if (nam <= co - 1 && nu == co - 1) cout << (Ckn(nam, co - 1) * mu(2, nam)) % MOD << '\n';
	else cout << 0 << '\n';
}
