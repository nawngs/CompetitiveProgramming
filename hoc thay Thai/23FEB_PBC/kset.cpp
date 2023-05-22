#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int prime[NMAX + 3], g[NMAX + 3], cnt[NMAX + 3], inv[NMAX + 3], fac[NMAX + 3], f[NMAX + 3], inv_[NMAX + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (1ll * fac[n] * 1ll * inv[k] % MOD * 1ll * inv[n - k]) % MOD;
}

ll solve(ll n, ll k) {
	ll res = mu(k, n);
	for (int i = 1; i <= k; i++) {
		res = (res + (i % 2 == 1 ? -1 : 1) * C(i, k) % MOD * mu(k - i, n) % MOD) % MOD;
		res = (res + MOD) % MOD;
	}
	return (res * 1ll * inv[k]) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	for (int i = 1; i <= NMAX; i++)
		prime[i] = i;
	for (int i = 2; i * i <= NMAX; i++)
		if (prime[i] == i)
			for (int j = i * i; j <= NMAX; j+=i) prime[j] = i;
	g[1] = 0, f[1] = 1;
	for (int i = 1; i <= NMAX; i++) 
		inv_[i] = mu(i, MOD - 2);
	for (int i = 2; i <= NMAX; i++) {
		f[i] = f[i - 1]; g[i] = g[i - 1];
		if (prime[i] == i) {
			g[i] ++;
			cnt[i] ++;
			continue;
		}
		int x = i;
		while (x > 1) {
			f[i] = (1ll * f[i] * 1ll * inv_[cnt[prime[x]]]) % MOD;
			cnt[prime[x]] ++;
			f[i] = (1ll * f[i] * 1ll * cnt[prime[x]]) % MOD;
			x /= prime[x];
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= NMAX; i++) 
		fac[i] = (1ll * fac[i - 1] * 1ll * i) % MOD;
	for (int i = 0; i <= NMAX; i++) 
		inv[i] = mu(fac[i], MOD - 2);
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		cout << ((solve(g[n], k - 1) + solve(g[n], k)) * 1ll * f[n]) % MOD << '\n';
	}
}