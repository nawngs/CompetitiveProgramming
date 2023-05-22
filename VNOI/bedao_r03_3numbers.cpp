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

ll n, ans = 0;

void sol() {
	cin >> n;
	for (ll i = 1; i <= cbrt(n); i++) {
		ll j = i;
		while (1) {
			ll tam = i * j;
			tam = n / tam;
			if (tam < j) break;
			if (i == j) {
				ans ++;
				ans += 3 * (tam - j);
			}
			else {
				ans += 3;
				ans += 6 * (tam - j);
			}
			j ++;
		}
	}
	cout << ans ;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
