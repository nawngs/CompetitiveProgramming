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

ll n;

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

ll catalan(ll x) {
	ll tam1 = 1, tam2, tam3;
	for (int i = 1; i <= 2 * x; i++) {
		tam1 = (tam1 * i) % MOD;
		if (i == x) tam3 = tam1;
		if (i == x + 1)tam2 = tam1;
	}
	return divide(tam1, (tam2 * tam3) % MOD);
}

void sol() {
	cin >> n;
	if (n % 2 == 1) {
		cout << 0 << '\n';
		return ;
	}
	cout << catalan(n / 2) << '\n';
}
 
int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
