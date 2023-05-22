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

ll a, b, c;

ll mu(ll a, ll b, ll mod) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, mod);
	x = (x * x) % mod;
	if (b % 2 == 1) x = (x * a) % mod;
	return x;
}

void sol() {
	cin >> a >> b >> c;
	cout << mu(a, mu(b, c, MOD - 1), MOD) << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
