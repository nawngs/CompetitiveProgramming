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

void calc(ll x) {
	ll tam = n / x;
	if ((tam - x + 1) % 2 != 0) return ;
	ll l = (tam - x + 1) / 2;
	if (l <= 0) return ;
	cout << l << " " << l + x - 1 << '\n';
}

void sol() {
	cin >> n;
	n *= 2;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			calc(i);
			if (i != n / i) calc(n / i);
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
