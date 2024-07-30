//[FINISHED]
#include <bits/stdc++.h>

#define name "cinema"
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
const int NMAX = 9e5;
const ll MOD = 998244353;
const ll BASE = 2309;

ll n, a[NMAX + 3], fac[NMAX + 3], inv[NMAX + 3], pre[NMAX + 3], nxt[NMAX + 3], s[NMAX + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

ll solve(int l, int r) {
	if (r - l + 1 == n) return 1;
	if (r - l + 1 == 1 && a[l] != 1) {
		ll res = 0;
		if (l >= a[l] && s[l - 1] - s[l - a[l]] == 0) {
			res = (solve(l - a[l] + 1, l) * mu(2, a[l] - 2)) % MOD;
		}
		if (r + a[l] - 1 <= n && s[r + a[l] - 1] - s[r] == 0) 
			res = (res + (solve(l, l + a[l] - 1) * mu(2, a[l] - 2))) % MOD;
		return res;
	} 
	int vall = a[pre[l - 1]], valr = a[nxt[r + 1]];
	if (min(vall, valr) < r - l + 1) return 0;
	if (min(vall, valr) == n + 1) {
		//cout << l - 1 << " " << n - (r - l + 1) << " " << C(l - 1, n - (r - l + 1)) << '\n';
		return C(l - 1, n - (r - l + 1));
	}
	if (vall < valr) {
		int delta = vall - (r - l + 1) - 1;
		if (l - pre[l - 1] - 1 > delta) return 0;
		int diff = delta - (l - pre[l - 1] - 1);
		if (r + diff >= nxt[r + 1]) return 0;
		// cout << l << " " << r << " " << C(l - pre[l - 1] - 1, delta) * solve(pre[l - 1], r + diff) << '\n';
		return (C(l - pre[l - 1] - 1, delta) * solve(pre[l - 1], r + diff)) % MOD;
	}
	else {
		int delta = valr - (r - l + 1) - 1;
		// cout << nxt[r + 1] - r - 1 << " " << delta << '\n';
		if (nxt[r + 1] - r - 1 > delta) return 0;
		int diff = delta - (nxt[r + 1] - r - 1);
		if (l - diff <= pre[l - 1]) return 0;
		// cout << l << " " << r << " " << C(nxt[r + 1] - r - 1, delta) * solve(l - diff, nxt[r + 1]) << '\n';
		return (C(nxt[r + 1] - r - 1, delta) * solve(l - diff, nxt[r + 1])) % MOD;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	int pos = -1;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + (a[i] != 0);
		if (a[i] != 0 && (pos == -1 || a[pos] > a[i])) pos = i;
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	inv[n] = mu(fac[n], MOD - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	a[0] = a[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) pre[i] = pre[i - 1];
		else pre[i] = i;
	}
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 0) nxt[i] = nxt[i + 1];
		else nxt[i] = i;
	}
	inv[n] = mu(inv[n], MOD - 2);
	if (pos == -1) {
		cout << mu(2, n - 1) << '\n';
		return 0;
	}
	cout << solve(pos, pos);
}