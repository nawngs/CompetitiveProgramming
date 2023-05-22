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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, cnt = 1, sum = 1, product = 1, pre[100003], suff[100003];

pll a[100003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll divide(ll a, ll b) {
	return ((a % MOD) * (mu(b, MOD - 2) % MOD) + MOD) % MOD;
}

ll calc(ll l, ll r) {
	return (((l + r) * (r - l + 1)) / 2) % (MOD - 1);
} 

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		cnt = (cnt * (a[i].se + 1)) % MOD;
		sum = (sum * divide(mu(a[i].fi, a[i].se + 1) - 1, a[i].fi - 1)) % MOD;
	}	
	pre[0] = 1;
	for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] * (a[i].se + 1)) % (MOD - 1);
	suff[n + 1] = 1;
	for (int i = n; i >= 1; i--) suff[i] = (suff[i + 1] * (a[i].se + 1)) % (MOD - 1);
	for (int i = 1; i <= n; i++) {
		product = (product * mu(mu(a[i].fi, calc(1, a[i].se)), (pre[i - 1] * suff[i + 1]) % (MOD - 1))) % MOD;
	}
	cout << cnt << " " << sum << " " << product << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
