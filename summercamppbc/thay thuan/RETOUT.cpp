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

ll n, m, a[1000003], f[1003][5003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	ll up = 1, down = 1;
	for (ll i = n - k + 1; i <= n; i++) up = (up * (i % MOD)) % MOD;
	for (ll i = 1; i <= k; i++) down = (down * i) % MOD;
	return (up * mu(down, MOD - 2)) % MOD;
}

void sub2() {
	cout << Ckn(n - 1, m - 1) << '\n';
}

void sub13() {
	f[0][0] = 1;
	for (int i = 1;	i <= n; i++) {
		for (int j = a[i]; j <= m; j++) f[i][j] = (f[i][j - a[i]] + f[i - 1][j - a[i]]) % MOD;
	}
	cout << f[n][m] << '\n';
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];	
	if (n > 1000 && m >	 5000) sub2();
	else sub13();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
