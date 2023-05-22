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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int m, n;

ll fac[500003], inv[500003], fibo[500003];

vector < vector < ll > > dp;

vector < ll > f;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m >> n;
	fac[0] = 1; inv[0] = mu(fac[0], MOD - 2);
	for (int i = 1; i <= NMAX; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = mu(fac[i], MOD - 2);
	}
	if (n <= m) {
		dp.resize(m + 5);
		for (auto &x : dp) x.resize(n + 5);
		dp[1][0] = 1;
		for (int i = 1; i <= m; i++) 
			for (int j = 0; j <= n; j++) {
				if (dp[i][j] == 0) continue;
				for (int k = 1; k <= n - j; k++) 
					dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * C(k, n - j)) % MOD;
			}
		ll res = 0;
		for (int j = 0; j <= n; j++)
			res = (res + dp[m][j]) % MOD;
		cout << res;
	}
	else {
		f.resize(m + 5);
		fibo[0] = 1;
		for (int i = 1; i <= NMAX; i++)
			fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
		for (int i = 1; i <= m; i++) {
			f[i] = mu(fibo[i], n);
			for (int j = 1; j < i; j++) {
				f[i] = (f[i] - f[i - j] * mu(fibo[j], n)) % MOD;
				f[i] = (f[i] + MOD) % MOD;
			}
		}
		cout << f[m];
	}		
}