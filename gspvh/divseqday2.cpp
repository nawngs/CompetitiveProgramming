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

const string NAME = "divseq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k;

bool check[nmax + 5];

vector < ll > prime;

void sang() {
	memset(check, 1, sizeof(check));
	check[1] = check[0] = false;
	for (ll i = 2; i * i <= nmax; i++)
		if (check[i]) for (ll j = i * i; j <= nmax; j+=i) check[j] = false;
	for (ll i = 1; i <= nmax; i++) if (check[i]) prime.push_back(1ll * i); 
}

ll mu(ll a, ll b) {
	if (b == 1) return a;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	ll up = 1;
	ll down = 1;
	for (ll i = n; i >= n - k + 1; i--) up = (up * (i % MOD)) % MOD;
	for (ll i = 1; i <= k; i++) down = (down * (i % MOD)) % MOD;
	return (up * mu(down, MOD - 2)) % MOD;
}

bool check2(ll x) {
	ll tam = sqrtl(x);
	return (tam * tam == x);
}

void sol() {
	sang();
	cin >> n >> k;
	ll res = 1;
	for (auto x : prime) {
		ll dem = 0;
		while (n % x == 0) {
			n /= x;
			dem ++;
		}
		res = (res * Ckn(dem, dem + k - 1)) % MOD;
	}
	if (n != 1) res = (res * Ckn(1 + check2(n), (check2(n) + k))) % MOD;
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
