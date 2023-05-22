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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a, b;

//##############################################################################

void sol1() {
	ll sum = 0;
	a %= MOD;
	b %= MOD;
	for (int i = 1; i <= n; i++) sum = (sum + (a * i + b * (ll)sqrtl(i))) % MOD;
	cout << sum << '\n';
}

//##############################################################################

ll calc(ll l, ll r) {
	ll val1 = l + r;
	ll val2 = (r - l + 1);
	if (val1 % 2 == 0) return (((val1 / 2) % MOD) * (val2 % MOD)) % MOD;
	else return (((val2 / 2) % MOD) * (val1 % MOD)) % MOD;
}

void sol2() {
	cout << calc(1, n) << '\n';
}

//##############################################################################

void sol3() {
	a %= MOD;
	b %= MOD;
	ll res = (calc(1, n) * a) % MOD;
	for (ll i = 1; i <= sqrt(n); i++) {
		ll l = i * i;
		ll r = min(n + 1, (i + 1) * (i + 1));
		ll add = (b * (r - l)) % MOD;
		add = (add * i) % MOD;
		res = (res + add) % MOD;
	}
	cout << res << '\n';
}

int main() {
	fast;
	cin >> n >> a >> b;
	if (n <= 100) sol1();
	else if (a == 1 && b == 0) sol2();
	else sol3();
}
