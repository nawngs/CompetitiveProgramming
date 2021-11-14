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

const string NAME = "CountDivisor";
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

int main() {
	fast;
	fre();
	cin >> a >> b >> c;
	ll ans = 0;
	ll tam = __gcd(a, __gcd(b, c));
	for (int i = 1; i * i <= tam; i++) {
		if (tam % i == 0) {
			ans ++;
			if (tam / i != i) ans ++;
		}
	}
	cout << ans;
}
