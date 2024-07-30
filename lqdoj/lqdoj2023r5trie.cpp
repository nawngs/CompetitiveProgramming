#include <bits/stdc++.h>

#define name "trie"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, fac[NMAX + 3], inv[NMAX + 3];

int cnta[20], cntb[20];

string s;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(int k, int n) {
	if (k > n) return 0;
	if (k == 0) return 1;
	return (fac[n] * ((inv[k] * inv[n - k]) % MOD)) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (auto c : s) {
			if (c == 'a') cnta[i] ++;
			else cntb[i] ++;
		}
	}
	fac[0] = 1; inv[0] = mu(fac[0], MOD - 2);
	for (int i = 1; i <= NMAX; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = mu(fac[i], MOD - 2);
	}
	ll res = 0;
	for (int msk = 1; msk < (1 << n); msk++) {
		int mina = NMAX, minb = NMAX;
		for (int i = 0; i < n; i++) if (msk >> i & 1) mina = min(mina, cnta[i]), minb = min(minb, cntb[i]);
		// cout << mina << " " << minb << " " << C(minb + 1, minb + mina + 2) - 1 << '\n';
		if (__builtin_popcount(msk) & 1) res = (res + C(minb + 1, minb + mina + 2) - 1) % MOD;
		else  res = (res - C(minb + 1, minb + mina + 2) + 1 + MOD) % MOD;
	}
	cout << res;

}