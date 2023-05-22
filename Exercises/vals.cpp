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

const string NAME = "ValS";
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

ll n, k, a[100003], tich[100003];

void create() {
	tich[0] = 1;
	for (int i = 1; i <= 100000; i++) tich[i] = (tich[i - 1] * i) % MOD;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc_c(ll k, ll n) {
	ll tam = (tich[k] * tich[n - k]) % MOD;
	return (tich[n] * mu(tam, MOD - 2)) % MOD;
}

void sol() {
	create();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;	
	for (int i = k; i <= n; i++) ans = (ans + (calc_c(k - 1, i - 1) * a[i]) % MOD) % MOD;
	
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
