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

const string NAME = "permute";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[400003], factors[400003];

bool check[400003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	ll up_val = factors[n];
	ll down_val = (factors[n - k] * factors[k]) % MOD;
	return (up_val * mu(down_val, MOD - 2)) % MOD;
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	cin >> n;
	factors[0] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) factors[i] = (factors[i - 1] * i) % MOD;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i) {
			cout << 0 << '\n';
			return 0;
		}
		if (a[i] != -1) check[a[i]] = 1;
		else cnt ++;
	}
	ll dem = 0;
	for (int i = 1; i <= n; i++) if (a[i] == -1 && !check[i]) dem ++;
	ll res = factors[cnt];
	for (int i = 1; i <= dem; i++) {
		if (i % 2 == 1) res = (res - ((Ckn(i, dem) * factors[cnt - i]) % MOD) + 5 * MOD) % MOD;
		else res = (res + ((Ckn(i, dem) * factors[cnt - i]) % MOD) % MOD) % MOD;
	}
	cout << res;
}
