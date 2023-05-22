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

const string NAME = "sum2n";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k;

ll nhan(ll a, ll b, ll p) {
	if (b == 0) return 0;
	ll x = nhan(a, b / 2, p);
	x = (x + x) % p;
	if (b % 2 == 1) x = (x + a) % p;
	return x;
}

ll mu(ll a, ll b, ll p) {
	if (b == 0) return 1 % p;
	ll x = mu(a, b / 2, p);
	x = nhan(x, x, p);
	if (b % 2 == 1) x = nhan(x, a, p);
	return x;
}

int main() {
	fast;
	//fre();
	while (cin >> n >> k) {
		cout << (nhan(n - 1, mu(2, n, k), k) + 1) % k << '\n';
	}
}
