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

int m, k, f[2001][2001][2][2][2];

string a, b;

ll mu(int a, int b) {
	//cout << a << " " << b << '\n';
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % m;
	if (b % 2 == 1) x = (x * a) % m;
	return x;
}

int dp(int pos, int modm, bool less, bool mod2, bool has1, bool th) {
	if (pos == (th == 1 ? a.size() : b.size()) - 1) return (modm == 0);
	if (f[pos][modm][less][mod2][has1] != -1) return f[pos][modm][less][mod2][has1];
	int res = 0;
	if (!has1) {
		res += dp(pos + 1, modm, 1, mod2, has1, th);
		for (int i = 1; i <= 9; i++) {
			if (!mod2 && i == k) continue;
			if (mod2 && i != k) continue;
			if (less || i <= (th == 1 ? a[pos + 1] : b[pos + 1]) - '0')
				res += dp(pos + 1, (modm + i * mu(10, (th == 1 ? a.size() : b.size()) - 1 - pos - 1)) % m, (less || i < (th == 1 ? a[pos + 1] : b[pos + 1]) - '0'), !mod2, has1 || i != 0, th);
			res %= MOD;
		}
	} 
	else {
		for (int i = 0; i <= 9; i++) {
			if (!mod2 && i == k) continue;
			if (mod2 && i != k) continue;
			if (less || i <= (th == 1 ? a[pos + 1] : b[pos + 1]) - '0')
				res += dp(pos + 1, (modm + i * mu(10, (th == 1 ? a.size() : b.size()) - 1 - pos - 1)) % m, (less || i < (th == 1 ? a[pos + 1] : b[pos + 1]) - '0'), !mod2, has1 || i != 0, th);
			res %= MOD;
		}
	}
	f[pos][modm][less][mod2][has1] = res;
	return res;
}


int calc(string x) {
	memset(f, 255, sizeof(f));
	return dp(0, 0, 0, 0, 0, (x == a ? 1 : 0));
}

bool check(string x) {
	for (int i = 1; i < x.size(); i++) {
		if (i % 2 == 1 && x[i] - '0' == k) return false;
		if (i % 2 == 0 && x[i] - '0' != k) return false;
	}
	int tam = 1, s = 0;
	for (int i = x.size() - 1; i > 0; i--) {
		s = (s + tam * (x[i] - '0')) % m;
		tam = (tam * 10) % m;
	}
	return (s == 0);
}


int main() {
	fast;
	cin >> m >> k >> a >> b;
	a = ' ' + a;
	b = ' ' + b; 
	cout << (calc(b) - calc(a) + check(a)) % MOD;
}
