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

ll x, n;

void sol() {
	cin >> x >> n;
	if (x % 2 == 0) {
		ll tam = n / 2;
		if (n % 2 == 1) {
			if (tam % 2 == 1) x += n;
			else x -= n;
		}
		cout << x + (tam % 2 == 1) << '\n';
	}
	else {
		ll tam = n / 2;
		if (n % 2 == 1) {
			if (tam % 2 == 1) x -= n;
			else x += n;
		}
		cout << x - (tam % 2 == 1) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
