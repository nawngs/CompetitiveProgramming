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

const string NAME = "divexp";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int l, r, k;

ll mu(int a, int b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x);
	if (b % 2 == 1) x = (x * 1ll * a);
	return x;
}

void sol() {
	cin >> l >> r >> k;
	int divisors = 0;
	//cout << divisors << '\n';
	for (int i = 1; i <= r; i++) {
		int temp1 = l / i + (l % i != 0);
		int temp2 = r / i;
		divisors += (temp2 - temp1 + 1);
	}
for (int i = 1; i <= r; i++) {
		ll tam = mu(i, k);
		if (tam > r) break;
		int temp1 = l / tam + (l % tam != 0);
		int temp2 = r / tam;
		divisors -= (temp2 - temp1 + 1);
	}
	cout << divisors;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
