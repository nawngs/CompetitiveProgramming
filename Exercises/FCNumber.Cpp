#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

ll n, cnt[nmax + 5];

bool f[nmax + 5];

vector < ll > prime, a;

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = true;

	f[1] = f[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i]) for (int j = i * i; j <= nmax; j += i) f[j] = false;

	for (int i = 1; i <= nmax; i++) if (f[i]) prime.push_back(i);
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * (a % MOD)) % MOD;
	//cout << a << " " << b << " " << x << '\n';
	return (ll) x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("FCNumber.inp", "r", stdin);
	//freopen("FCNumber.out", "w", stdout);
	sang();
	cin >> n;
	ll res = 1;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a.push_back(x);
		for (auto j : prime) {
			while (a[i] % j == 0) {
				cnt[j] ++;
				a[i] /= j;
			}
		}
	}

	for (auto i : prime) {
		res = (res * mu(i, (cnt[i] / 3 + (cnt[i] % 3 != 0)) * 3)) % MOD;
	}

	vector < pll > b;
	for (int i = 0; i < n; i++) {
		ll tam = (ll) sqrtl(a[i]);
		if (tam * tam == a[i]) b.push_back({tam, tam});
		else b.push_back({a[i], 1});
	} 

	for (int i = 0; i < b.size(); i++) {
		if (b[i].fi != 1 && b[i].se != 1) continue;
		for (int j = 0; j < b.size(); j++) {
			if (i == j) continue;
			ll tam = __gcd(b[i].fi, b[j].fi);
			if (tam != 1) {
				b[i].fi = tam;
				b[i].se = a[i] / b[i].fi;
				break;
			}
			tam = __gcd(b[i].fi, b[j].se);
			if (tam != 1) {
				b[i].fi = tam;
				b[i].se = a[i] / b[i].fi;
				break;
			}
			tam = __gcd(b[i].se, b[j].fi);
			if (tam != 1) {
				b[i].fi = tam;
				b[i].se = a[i] / b[i].fi;
				break;
			}
			tam = __gcd(b[i].se, b[j].se);
			if (tam != 1) {
				b[i].fi = tam;
				b[i].se = a[i] / b[i].fi;
				break;
			}
		}
	}

	a.clear();
	for (int i = 0; i < b.size(); i++) {
		//cout << b[i].fi << " " << b[i].se << '\n';
		if (b[i].fi != 1) a.push_back(b[i].fi);
		if (b[i].se != 1) a.push_back(b[i].se);
	}

	sort(a.begin(), a.end());
	ll dem = 1;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			res = (res * (mu(a[i - 1], (dem / 3 + (dem % 3 != 0) * 3)))) % MOD;
			dem = 1;
		}
	}
	if (a.size()) res = (res * (mu(a[a.size() - 1], (dem / 3 + (dem % 3 != 0) * 3)))) % MOD;

	cout << res << '\n';
}
