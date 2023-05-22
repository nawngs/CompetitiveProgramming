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

const string NAME = "GCDLCM";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 15e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll m, n, k, f[nmax + 3], ucln[nmax + 3], bcnn[nmax + 3];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * i; j <= nmax; j+=i) f[j] = i;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main() {
	fast;
	//fre();
	cin >> m >> n >> k;
	sang();
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		while (x > 1) {
			ucln[f[x]] ++;
			x /= f[x];
		}
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x > 1) {
			bcnn[f[x]] ++;
			x /= f[x];
		}
	}
	if (k == 1) {
		for (int i = 2; i <= nmax; i++) {
			if (f[i] != i) continue;
			if (k == 1 && ucln[i] != bcnn[i]) {
				cout << 0 << '\n';
				return 0;
			}
		}
		cout << 1 << '\n';
		return 0;
	}
	if (k == 2) {
		ll res = 1;
		for (int i = 2; i <= nmax; i++) {
			if (f[i] != i) continue;
			if (ucln[i] > bcnn[i]) {
				cout << 0 << '\n';
				return 0;
			}
			if (ucln[i] == bcnn[i]) continue;
			ll tam = (k * (k - 1));
			res = (res * tam) % MOD;
		}
		cout << res;
		return 0;
	}
	ll res = 1;
	for (int i = 2; i <= nmax; i++) {
		if (f[i] != i) continue;
		if (ucln[i] > bcnn[i]) {
			cout << 0 << '\n';
			return 0;
		}
		if (ucln[i] == bcnn[i]) continue;
		ll tam = mu(bcnn[i] - ucln[i] + 1, k);
		ll tam2 = mu(bcnn[i] - ucln[i], k);
		ll tam3 = mu(bcnn[i] - ucln[i] - 1, k);
		//cout << tam << " " << tam2 << '\n';
		tam = (tam - 2 * tam2 + tam3 + MOD + MOD) % MOD;
		res = (res * tam) % MOD;
	}
	cout << res;
}

 