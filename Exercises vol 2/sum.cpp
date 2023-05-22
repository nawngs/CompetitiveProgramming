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

const string NAME = "sum";
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

ld a, b;

ll calc(ll a, ll b) {
	ll x = b, y = a + b, z = 2 * b + a;
	bool th2 = false, th3 = false;
	if (!th2 && x % 2 == 0) {
		th2 = 1;
		x /= 2;
	}
	if (!th2 && y % 2 == 0) {
		th2 = 1;
		y /= 2;
	}
	if (!th2 && z % 2 == 0) {
		th2 = 1;
		z /= 2;
	}	
	if (!th3 && x % 3 == 0) {
		th3 = 1;
		x /= 3;
	}
	if (!th3 && y % 3 == 0) {
		th3 = 1;
		y /= 3;
	}
	if (!th3 && z % 3 == 0) {
		th3 = 1;
		z /= 3;
	}
	return ((x * y) % MOD * z) % MOD;
}

int main() {
	fast;
	fre();
	cin >> a >> b;
	a = ceill(a);
	b = floor(b);
	cout << (calc(1, b) - calc(1, a - 1) + MOD) % MOD;
}
