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

const string NAME = "NumEqual";
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

ll n, k, s[1000005];

void create() {
	s[1] = 1;
	for (int i = 2; i <= 1000000; i++) s[i] = (s[i - 1] * i) % MOD;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc_c(ll k, ll n) {
	ll tam = (s[n - k] * s[k]) % MOD;
	return (s[n] * mu(tam, MOD - 2)) % MOD;
}


void sol() {
	cin >> n >> k;
	if (k == 1) {
		cout << 1 << '\n';
		return ;
	}
	create();
	cout << calc_c(k - 1, n - 1) << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
