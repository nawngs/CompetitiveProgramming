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
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll f[nmax + 3], gt[nmax + 3], inv[nmax + 3], m, n;

void sieve() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) 
			for (int j = 2 * i; j <= nmax; j+=i) 
				f[j] = i;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return ((gt[n] * inv[n - k]) % MOD * inv[k]) % MOD;
}

void sol() {
	cin >> m >> n;
	vector < int > prime;
	int pre = -1, x = m;
	while (x > 1) {
		if (pre != f[x]) {
			prime.push_back(pre);
			pre = f[x];
		}
		x /= f[x];
	}
	prime.push_back(pre);
	ll res = C(n - 1, m - 1);
	for (int bit = 1; bit < (1 << prime.size()); bit++) {
		ll cur = 1;
		for (int i = 0; i < prime.size(); i++) 
			if ((bit >> i) & 1) cur *= prime[i];
		if (__builtin_popcount(bit) & 1) res -= C(n - 1, (m / cur) - 1);
		else res += C(n - 1, (m / cur) - 1);
		res = (res % MOD + MOD) % MOD;
	}
	cout << res << '\n';
}

int main() {
	fast;
	//fre();
	sieve();
	gt[0] = 1;
	for (int i = 1; i <= nmax; i++) 
		gt[i] = (gt[i - 1] * i) % MOD;
	inv[nmax] = mu(gt[nmax], MOD - 2);
	for (int i = nmax - 1; i >= 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	}
	int t = 1;
	cin >> t;
	while (t --) sol();
}
