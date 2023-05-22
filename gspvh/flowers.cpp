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

const string NAME = "flowers";
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

ll p, n, m, k, frac[1000003];

void init() {
	frac[0] = 1;
	for (int i = 1; i <= 1e6; i++) frac[i] = (frac[i - 1] * i) % p;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % p;
	if (b % 2 == 1) x = (x * a) % p;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % p, p - 2)) % p;
}


void sub12() {
	cout << ((C(k, n - 1) * m) % p * mu(m - 1, k)) % p << '\n';
}


ll divab(ll a, ll b) {
	return (a * mu(b, p - 2)) % p;
}

void sub3() {
	ll a = 1;
	for (int i = n - 1; i >= n - k; i--) a = (a * i) % p;
	cout << ((divab(a, frac[k]) * m) % p * mu(m - 1, k)) % p << '\n';
}

ll f[1000003], cnt[1000003];

void sang() {
	for (int i = 1; i <= 1e6; i++) f[i] = i;
	for (int i = 2; i * i <= 1e6; i++)
		if (f[i]== i) for (int j = i * i; j <= 1e6; j += i) f[j] = i;
}

void sub4() {
	memset(cnt, 0, sizeof(cnt));
	for (int i = n - k; i <= n - 1; i++) {
		int x = i;
		while (x > 1) {
			cnt[f[x]] ++;
			x /= f[x];
		}
	}
	for (int i = 2; i <= k; i++) {
		int x = i;
		while (x > 1) {
			cnt[f[x]] --;
			x /= f[x];
		}
	}
	ll res = 1;
	for (int i = 1; i <= 1e6; i++) res = (res * mu(i, cnt[i])) % p;
	cout << ((res * m) % p * mu(m - 1, k)) % p << '\n';
}

void sol() {
	cin >> n >> m >> k;		
	if (p == 998244353 && n <= 1000000) sub12();
	else if (p == 998244353) sub3();
	else sub4();
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t >> p;
	if (t <= 50) sang();
	init();
	while (t --) sol();
}