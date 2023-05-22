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

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x = x * a;
	return x;
}

void sol() {
	ll ans = 0;
	for (int i = 0; i <= 29; i++) {
		ll a = mu(2, i) - ans;
		ll b = a + mu(2, i + 1);
		cout << "? " << a << " " << b << '\n';
		ll tam;
		cin >> tam;
		if (tam % mu(2, i + 1) == 0) ans += mu(2, i);
	}
	cout << "! " << ans << '\n';	
}

int main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
