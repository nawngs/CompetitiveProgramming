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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, l, r;

vector < ll > prime;

vector < pll > temp;

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 2; i <= nmax; i++) {
		if (n % i == 0) {
			prime.push_back(i);
			while (n % i == 0) 
				n /= i;
		}
	}
	if (n != 1) prime.push_back(n);
	for (int i = 1; i < (1 << (prime.size())); i++) {
		ll cur = 1;
		for (int bit = 0; bit < prime.size(); bit++) 
			if ((i >> bit) & 1) cur *= prime[bit];
		temp.push_back({cur, __builtin_popcount(i)});
	}
	while (m--) {
		cin >> l >> r;
		ll res = 0;
		for (auto x : temp) {
			if (x.se % 2 == 1) res += r / x.fi - (l + x.fi - 1) / x.fi + 1;
			else res -= r / x.fi - (l + x.fi - 1) / x.fi + 1;
		}
		cout << (r - l + 1) - res << '\n';
	}
}
