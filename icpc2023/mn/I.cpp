#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 5e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[NMAX + 3], dp[NMAX + 3][NMAX + 3], fac[NMAX + 3], inv[NMAX + 3], pw[NMAX + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(int k, int n) {
	if (k > n) return 0;
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
	fac[0] = 1; inv[0] = mu(fac[0], MOD - 2); pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[x] ++;
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = mu(fac[i], MOD - 2);
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	ll res = 0, cnt = 0, pre = 0;
	dp[0][0] = 1; pre = 0;
	for (int x = 1; x <= NMAX; x++) if (a[x]) {
		ll temp = pw[cnt], cur = 0;
		for (int i = 2; i <= a[x]; i++) {
			res = (res + (temp - (i == 2)) * C(i, a[x])) % MOD;
		}
		for (int i = 0; i <= x; i++) cur = (cur + dp[pre][i]) % MOD;
		temp = (temp - cur + MOD) % MOD;
		temp = (temp * a[x]) % MOD;
		res = (res + temp) % MOD;
		for (int i = NMAX; i >= 0; i--) 
			for (int j = 0; j <= a[x]; j++)
				if (i >= j * x) dp[x][i] = (dp[x][i] + C(j, a[x]) * dp[pre][i - j * x]) % MOD;
		cnt += a[x]; pre = x;
		// cout << x << " " << res << '\n';
	}
	cout << res;
}